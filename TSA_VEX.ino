#include <Servo.h>
#include <Victor.h>
#include <Spike.h>

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

#define LIFT_LIMIT_DOWN 10
#define LIFT_LIMIT_UP 11

#define LIFT_RUN_UP 1
#define LIFT_RUN_DOWN 2


Servo leftDrive;
Servo rightDrive;

//Spike collector(6,7);
//Spike lift(8,9);


byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(10,0,0,177);
EthernetUDP UDP;

unsigned long timeoutAt = 0;

struct ControlState
{
  byte leftDrive;
  byte rightDrive;
  byte collectorState; 
  byte liftState;
} controlState;


int calcPWMValue(byte value)
{
  float v = ((float)value*(500.0f/127.0f))+1000.0f;
  return int(floor(v));
}

void doCommunication()
{
  if ( UDP.parsePacket() )
  {    
    char packetBuffer[UDP_TX_PACKET_MAX_SIZE];
    UDP.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
    controlState.leftDrive = packetBuffer[0];
    controlState.rightDrive = packetBuffer[1];
    controlState.collectorState = packetBuffer[2];
    controlState.liftState = packetBuffer[3];
    timeoutAt = millis()+500;
  }
  
  if ( millis() > timeoutAt )
  {
    controlState.leftDrive = 127;
    controlState.rightDrive = 127;
    controlState.collectorState = 0;
  }
}

void drivetrainUpdate()
{
  leftDrive.writeMicroseconds(calcPWMValue(controlState.leftDrive));
  rightDrive.writeMicroseconds(calcPWMValue(controlState.rightDrive));
}

void updateLift()
{
  
}

void setup() {
  
  leftDrive.attach(3);
  rightDrive.attach(5);
  
  Ethernet.begin(mac,ip);
  UDP.begin(8888);
  Serial.begin(9600);
  //pinMode(LIFT_LIMIT_UP, INPUT_PULLUP);
  //pinMode(LIFT_LIMIT_DOWN, INPUT_PULLUP);
}



void loop() {
  doCommunication();
  drivetrainUpdate();
  //updateLift();
}

