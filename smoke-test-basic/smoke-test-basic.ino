// Use this code to test the robot as well as the Robot library
// The basic smoke test just tests the motors.  No servo/ultrasonic.

#include <Servo.h>
#include <Robot.h>


// --------------------------------------------------------------------------- Motors
int MOTOR_LEFT[] = {9, 8};
int MOTOR_RIGHT[] = {7, 6};



// --------------------------------------------------------------------------- Initialize Robot

Robot robot(MOTOR_LEFT, MOTOR_RIGHT);

void setup() {
  Serial.begin(9600);

  //setup robot
  robot.setup();

}

// --------------------------------------------------------------------------- Loop
void loop() {

  robot.drive_forward(1000);
  robot.motor_stop();
  Serial.println("1");

  robot.drive_backward(1000);
  robot.motor_stop();
  Serial.println("2");

  robot.turn_left(1000);
  robot.motor_stop();
  Serial.println("3");

  robot.turn_right(1000);
  robot.motor_stop();
  Serial.println("4");

  robot.motor_stop();
  Serial.println("5");

}

