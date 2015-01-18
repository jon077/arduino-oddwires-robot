#include "Arduino.h"
#include "Robot.h"

Robot::Robot(int* motor_left, int* motor_right)
{
  _motor_left = motor_left;
  _motor_right = motor_right;
}


void Robot::drive_forward(int seconds){
  digitalWrite(_motor_left[0], HIGH);
  digitalWrite(_motor_left[1], LOW);

  digitalWrite(_motor_right[0], HIGH);
  digitalWrite(_motor_right[1], LOW);
  delay(seconds);
}
