#include "Arduino.h"
#include "Robot.h"



/*************
* Commands to make creating sketches with the robot easier
*
* NOTE:  The motor functions have a milliseconds argument.   Milliseconds is provided for convenience.
* It may be desired to have a short delay so other commands can be called while the motor is running.
*************/
Robot::Robot(int* motor_left, int* motor_right, int trigger_pin, int echo_pin)
{
  _motor_left = motor_left;
  _motor_right = motor_right;
  _trigger_pin = trigger_pin;
  _echo_pin = echo_pin;
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


/*****
* Uses the ultrasonic sensor to calculate the distance in inches
***/
long Robot::calculate_inches(){
  //write to the trigger
  digitalWrite(_trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigger_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigger_pin, LOW);

  //read duration
  long time = pulseIn(_echo_pin, HIGH);

  return time / 74 / 2;
}
