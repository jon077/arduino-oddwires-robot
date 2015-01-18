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

const int SERVO_PIN = 5;

// --------------------------------------------------------------------------- Ultrasonic sensor

const int TRIGGER_PIN = 4;
const int ECHO_PIN = 2;



Servo servo; // create servo object to control a servo.  a maximum of eight servo objects can be created

Robot robot(MOTOR_LEFT, MOTOR_RIGHT);


// --------------------------------------------------------------------------- Setup
void setup() {
  delay(2000); // delay so to allow time to upload new sketch before wheels start to turn

  Serial.begin(9600);

  // Setup motors
  int i;
  for(i = 0; i < 2; i++){
    pinMode(MOTOR_LEFT[i], OUTPUT);
    pinMode(MOTOR_RIGHT[i], OUTPUT);
  }

  //Setup servo
  servo.attach(SERVO_PIN); // attaches the servo on pin 9 to the servo object


  //Setup ultrasonic sensor
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  
}



void loop(){

  //look forward
  servo.write(90);

  //Measure distance
  long inches = calculate_inches();
  Serial.println(" - inches: " + inches );

  if(inches > 12){
    robot.drive_forward(100);
  }else{
    motor_stop();

    //turn head left and calculate distance
    servo.write(0);    delay(1500);
    long left_inches = calculate_inches();
    Serial.println("left_inches: " + left_inches);


    servo.write(180);  delay(1500);
    long right_inches = calculate_inches();
    Serial.println("right_inches: " + right_inches);

    servo.write(90);  delay(1000);
    if(right_inches < left_inches){
        turn_left(500);
    }else{
        turn_right(500);
    }
  }
}



// --------------------------------------------------------------------------- Drive


void motor_stop(){
  digitalWrite(MOTOR_LEFT[0], LOW);
  digitalWrite(MOTOR_LEFT[1], LOW);

  digitalWrite(MOTOR_RIGHT[0], LOW);
  digitalWrite(MOTOR_RIGHT[1], LOW);
  delay(25);
}



void drive_backward(int seconds){
  digitalWrite(MOTOR_LEFT[0], LOW);
  digitalWrite(MOTOR_LEFT[1], HIGH);

  digitalWrite(MOTOR_RIGHT[0], LOW);
  digitalWrite(MOTOR_RIGHT[1], HIGH);
  delay(seconds);
}


void turn_left(int seconds){
  digitalWrite(MOTOR_LEFT[0], LOW);
  digitalWrite(MOTOR_LEFT[1], HIGH);

  digitalWrite(MOTOR_RIGHT[0], HIGH);
  digitalWrite(MOTOR_RIGHT[1], LOW);
  delay(seconds);
}


void turn_right(int seconds){
  digitalWrite(MOTOR_LEFT[0], HIGH);
  digitalWrite(MOTOR_LEFT[1], LOW);

  digitalWrite(MOTOR_RIGHT[0], LOW);
  digitalWrite(MOTOR_RIGHT[1], HIGH);

  delay(seconds);
}




long calculate_inches(){
  //write to the trigger
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  //read duration
  long time = pulseIn(ECHO_PIN, HIGH);

  return time / 74 / 2;
}
