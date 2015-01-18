#include "Arduino.h"

#ifndef Robot_h
#define Robot_h

class Robot
{
public:
  Robot(int* motor_left, int* motor_right);
  void drive_forward(int seconds);
private:
  int* _motor_left;
  int* _motor_right;
};

#endif
