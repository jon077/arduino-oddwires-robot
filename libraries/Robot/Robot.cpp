#include "Arduino.h"
#include "Servo.h"
#include "Robot.h"




/*************
* Commands to make creating sketches with the robot easier
*
* NOTE:  The motor functions have a milliseconds argument.   Milliseconds is provided for convenience.
* It may be desired to have a short delay so other commands can be called while the motor is running.
*************/
Robot::Robot(int* motor_left, int* motor_right, int trigger_pin, int echo_pin, int servo_pin, Servo servo)
{
  _motor_left = motor_left;
  _motor_right = motor_right;
  _trigger_pin = trigger_pin;
  _echo_pin = echo_pin;
  _servo_pin = servo_pin;
  _servo = servo;

  LEFT = 0;
  FORWARD = 90;
  RIGHT = 180;

}


/******
* Setup components during startup.  Sets up motor, servo, and ultrasonic
******/
void Robot::setup(){

  // Setup motors
  int i;
  for(i = 0; i < 2; i++){
    pinMode(_motor_left[i], OUTPUT);
    pinMode(_motor_right[i], OUTPUT);
  }


  //Setup servo
  _servo.attach(_servo_pin); // attaches the servo on pin 9 to the servo object


  //Setup ultrasonic sensor
  pinMode(_trigger_pin, OUTPUT);
  pinMode(_echo_pin, INPUT);
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
void Robot::drive_backward(int milliseconds){
  digitalWrite(_motor_left[0], LOW);
  digitalWrite(_motor_left[1], HIGH);

  digitalWrite(_motor_right[0], LOW);
  digitalWrite(_motor_right[1], HIGH);
  delay(milliseconds);
}



/*****
* Turns robot left delaying for milliseconds
***/
void Robot::turn_left(int milliseconds){
  digitalWrite(_motor_left[0], LOW);
  digitalWrite(_motor_left[1], HIGH);

  digitalWrite(_motor_right[0], HIGH);
  digitalWrite(_motor_right[1], LOW);
  delay(milliseconds);
}

/*****
* Turns robot right delaying for milliseconds
***/
void Robot::turn_right(int milliseconds){
  digitalWrite(_motor_left[0], HIGH);
  digitalWrite(_motor_left[1], LOW);

  digitalWrite(_motor_right[0], LOW);
  digitalWrite(_motor_right[1], HIGH);

  delay(milliseconds);
}


/*****
* Turns to servo to look in the given position and waits the given milliseconds.
*
* XXX:  Need to make constants in the library for left/right/forward.
***/
void Robot::look(int pos, int milliseconds){
  _servo.write(pos);
  delay(milliseconds);
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
