#include "Arduino.h"

#ifndef Robot_h
#define Robot_h

class Robot
{
public:
  Robot(int* motor_left, int* motor_right, int trigger_pin, int echo_pin);
  void motor_stop();
  void drive_forward(int seconds);
  void drive_backward(int seconds);
  void turn_left(int seconds);
  void turn_right(int seconds);
  long calculate_inches();

private:
  int* _motor_left;
  int* _motor_right;
  int _trigger_pin;
  int _echo_pin;
};

#endif
