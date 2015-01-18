#include "Arduino.h"

#ifndef Robot_h
#define Robot_h

class Robot
{
public:
  Robot(int* motor_left, int* motor_right);
  void motor_stop();
  void drive_forward(int seconds);
  void drive_backward(int seconds);
  void turn_left(int seconds);
  void turn_right(int seconds);

private:
  int* _motor_left;
  int* _motor_right;
};

#endif
