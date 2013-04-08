# TSA VEX

##### Libraries 
Put the Victor and Spike libraries in the libs folder into ~/Documents/Arduino/libraries/


##### Communication
4 unsigned bytes are sent from the driver station over UDP on port 8888 to the robot every 50ms

Packet Structure:
0. Left Drive
1. Right Drive
2. Collector State
3. Lift State

An instance of the ControlState data structure is populated with this data ( named controlState )

```
struct ControlState
{
  byte leftDrive;
  byte rightDrive;
  byte collectorState; 
  byte liftState;
};
```


Left and Right contain values from 0-254 representing the current motor speed. 127 is stopped.

Collector states are
0. Off
1. Forward
2. Reverse

Lift states are
0. Down
1. Up

The robot controller will handle moving the lift to the setpoint.

