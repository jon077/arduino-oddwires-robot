#include "Arduino.h"
#include "Robot.h"


/*************
* Commands to make creating sketches with the robot easier
*
* NOTE:  The motor functions have a milliseconds argument.   Milliseconds is provided for convenience.
* It may be desired to have a short delay so other commands can be called while the motor is running.
*************/
Robot::Robot(int* motor_left, int* motor_right)
{
  _motor_left = motor_left;
  _motor_right = motor_right;
}



/*****
* Stops both motors
***/
void Robot::motor_stop(){
  digitalWrite(_motor_left[0], LOW);
  digitalWrite(_motor_left[1], LOW);

  digitalWrite(_motor_right[0], LOW);
  digitalWrite(_motor_right[1], LOW);
  delay(25);
}



/*****
* Drives forward delaying for milliseconds
***/
void Robot::drive_forward(int milliseconds){
  digitalWrite(_motor_left[0], HIGH);
  digitalWrite(_motor_left[1], LOW);

  digitalWrite(_motor_right[0], HIGH);
  digitalWrite(_motor_right[1], LOW);
  delay(milliseconds);
}



/*****
* Drives backward delaying for milliseconds
***/
void Robot::drive_backward(int seconds){
  digitalWrite(_motor_left[0], LOW);
  digitalWrite(_motor_left[1], HIGH);

  digitalWrite(_motor_right[0], LOW);
  digitalWrite(_motor_right[1], HIGH);
  delay(seconds);
}



/*****
* Turns robot left delaying for milliseconds
***/
void Robot::turn_left(int seconds){
  digitalWrite(_motor_left[0], LOW);
  digitalWrite(_motor_left[1], HIGH);

  digitalWrite(_motor_right[0], HIGH);
  digitalWrite(_motor_right[1], LOW);
  delay(seconds);
}

/*****
* Turns robot right delaying for milliseconds
***/
void Robot::turn_right(int seconds){
  digitalWrite(_motor_left[0], HIGH);
  digitalWrite(_motor_left[1], LOW);

  digitalWrite(_motor_right[0], LOW);
  digitalWrite(_motor_right[1], HIGH);

  delay(seconds);
}
