#include "Arduino.h"
#include "Servo.h"

#ifndef Robot_h
#define Robot_h

class Robot
{
public:
  Robot(int* motor_left, int* motor_right, int trigger_pin, int echo_pin, int servo_pin, Servo servo);
  void motor_stop();
  void drive_forward(int milliseconds);
  void drive_backward(int milliseconds);
  void turn_left(int milliseconds);
  void turn_right(int milliseconds);
  long calculate_inches();
  void setup();
  void look(int pos, int milliseconds);

private:
  int* _motor_left;
  int* _motor_right;
  int _trigger_pin;
  int _echo_pin;
  int _servo_pin;
  Servo _servo;
};

#endif
