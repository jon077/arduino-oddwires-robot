/*************************************************
* Logic for follow wall.  Following a wall is basically staying as close
* as possible to a wall, then when a corner is hit guess at a turn and 
* try again.
*
* To make life simplier, assume the room is small (not a gym).  Then 
* a single routine can be defined to find a wall and follow.  Basically, 
* navigate an arc towards the wall, stopping if you get too close.
* 
* Making life complex, the ultrasonic sensor tends to bounce diagonally
* off walls, which makes measuring angles against surfaces difficult.
* 
* Arc logic:
*     * Check distance forward.  If distance is < 12in, turn left ~90 degrees.  
*       Skip the below logic and measure forward (basically find a way out)
*    * Check distance to the right.  If distance is < 12in, turn left a small 
*      amount
*    * Go forward for one second
*
*************************************************/


#include <Servo.h>
#include <Robot.h>


// --------------------------------------------------------------------------- Motors
int MOTOR_LEFT[] = {9, 8};
int MOTOR_RIGHT[] = {7, 6};



// --------------------------------------------------------------------------- Ultrasonic sensor


Servo servo1; // create servo object to control a servo.  a maximum of eight servo objects can be created

Robot robot(MOTOR_LEFT, MOTOR_RIGHT);


// --------------------------------------------------------------------------- Setup
void setup() {
  delay(2000); // delay so to allow time to upload new sketch before wheels start to turn

  Serial.begin(9600);

  //setup robot
  robot.setup();
}



void loop(){

  //time to measure
  robot.motor_stop();  
  robot.look(robot.FORWARD,100);

  //Measure distance
  long fwdinches = robot.calculate_inches();
  Serial.println(" - fwd inches: " + fwdinches );
  
  if(fwdinches < 12){
    robot.turn_left(500);  //~90 degrees
  }else{
    robot.look(robot.RIGHT,100);
    long rightinches = robot.calculate_inches();
    Serial.println(" - right inches: " + rightinches );
    
    if(rightinches < 12){
      robot.turn_left(20);
    }else if(rightinches > 16){
      robot.turn_right(20);
    }
    
    robot.drive_forward(1000);
  }
}



