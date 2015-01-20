// Use this code to test the entire robot functionality


#include <Servo.h>
#include <Robot.h>

// --------------------------------------------------------------------------- Motors
int MOTOR_LEFT[] = {9, 8};
int MOTOR_RIGHT[] = {7, 6};


// --------------------------------------------------------------------------- Initialize Robot

Robot robot(MOTOR_LEFT, MOTOR_RIGHT);



// --------------------------------------------------------------------------- Setup
void setup() {
  Serial.begin(9600);

  //setup robot
  robot.setup();
  
  //test servo
  int pos = 0; // variable to store the servo position

  // goes from 0 degrees to 180 degrees in steps of 1 degree
  // tell servo to go to position in variable 'pos' // waits 15ms for the servo to reach the position
  for(pos = 0; pos < 180; pos += 1) {
    robot.look(pos, 15);
  }

  // goes from 180 degrees to 0 degrees
  // tell servo to go to position in variable 'pos' // waits 15ms for the servo to reach the position
  for(pos = 180; pos>=1; pos-=1) {
    robot.look(pos, 15);
  }

  delay(5000); run();

}



// --------------------------------------------------------------------------- Loop
void run() {


   for(int i = 0; i < 360; i++){
     robot.drive_forward(10);
     robot.turn_right(4);
   }

   robot.drive_forward(100);

   for(int i = 0; i < 360; i++){
     robot.drive_forward(9);
     robot.turn_left(3);
   }


   robot.motor_stop();
}


void loop(){
  
  long inches = robot.calculate_inches();

  Serial.print("Distance = "); Serial.print(inches); Serial.println(" inches");
}

