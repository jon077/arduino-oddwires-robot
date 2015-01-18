/*************************************************
* Logic for self-navigation.
*
* 1.  Drive forward until within 12in of something.
* 2.  If closer than 12in:
*        Stop
*        Turn left
*        Measure distance
*        Turn right
*        Measure distance.
* 3.  Turn in the direction of the longest distance and drive forward
*
*************************************************/


#include <Servo.h>
#include <Robot.h>


// --------------------------------------------------------------------------- Motors
int MOTOR_LEFT[] = {9, 8};
int MOTOR_RIGHT[] = {7, 6};


// --------------------------------------------------------------------------- Servo

int SERVO_PIN = 5;

// --------------------------------------------------------------------------- Ultrasonic sensor

int TRIGGER_PIN = 4;
int ECHO_PIN = 2;



Servo servo; // create servo object to control a servo.  a maximum of eight servo objects can be created

Robot robot(MOTOR_LEFT, MOTOR_RIGHT, TRIGGER_PIN, ECHO_PIN, SERVO_PIN, servo);


// --------------------------------------------------------------------------- Setup
void setup() {
  delay(2000); // delay so to allow time to upload new sketch before wheels start to turn

  Serial.begin(9600);

  //setup robot
  robot.setup();
}



void loop(){

  //look forward
  robot.look(90,100);

  //Measure distance
  long inches = robot.calculate_inches();
  Serial.println(" - inches: " + inches );

  if(inches > 12){
    robot.drive_forward(100);
  }else{
    robot.motor_stop();

    //turn head left and calculate distance
    robot.look(0, 1500);
    long left_inches = robot.calculate_inches();
    Serial.println("left_inches: " + left_inches);


    robot.look(180, 1500);
    long right_inches = robot.calculate_inches();
    Serial.println("right_inches: " + right_inches);

    robot.look(90, 1000);
    if(right_inches < left_inches){
        robot.turn_left(500);
    }else{
        robot.turn_right(500);
    }
  }
}



