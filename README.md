# arduino-oddwires-robot

## Documentation
See documents/RoboticsKitV2.3.pdf for the original PDF documentation from oddwires.  The robot was constructed strictly following the instructions.


## Library
* Robot library has the functions for interacting with the robot.  It should be used whenever possible.


## Sketches

### Smoke Test Basic
Basic sketch to demonstrate the functionality of the motor only

### Smoke Test Everything
Basic sketch to demonstrate the functionality of all components

### Self Navigation
Self navigation sketch to drive forward until within 12in of something.  Once within 12in of something,
measure left/right and go in the direction of the largest distance

Overall, it works pretty well, but sometimes the sound bounces off of diagonal walls.  Measuring perpendicular works really well.

### Follow Wall
Follow wall is an attempt to navigate the robot along a wall using the ultrasonic sensor to feel its way down the wall.

## Next Steps
* See the issues for next steps
