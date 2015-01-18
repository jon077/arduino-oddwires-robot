// Use this code to test the entire robot functionality


#include <Servo.h>

// --------------------------------------------------------------------------- Motors
const int motor_left[] = {9, 8};
const int motor_right[] = {7, 6};


// --------------------------------------------------------------------------- Servo

const int SERVO_PIN = 5;

// --------------------------------------------------------------------------- Ultrasonic sensor

const int TRIGGER_PIN = 4;
const int ECHO_PIN = 2;



Servo servo; // create servo object to control a servo.  a maximum of eight servo objects can be created



// --------------------------------------------------------------------------- Setup
void setup() {
  Serial.begin(9600);

  // Setup motors
  int i;
  for(i = 0; i < 2; i++){
    pinMode(motor_left[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
  }

  //Setup servo
  servo.attach(SERVO_PIN); // attaches the servo on pin 9 to the servo object


  //Setup ultrasonic sensor
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);




  int pos = 0; // variable to store the servo position

  // goes from 0 degrees to 180 degrees in steps of 1 degree
  // tell servo to go to position in variable 'pos' // waits 15ms for the servo to reach the position
  for(pos = 0; pos < 180; pos += 1) {
    servo.write(pos); delay(15);
  }

  // goes from 180 degrees to 0 degrees
  // tell servo to go to position in variable 'pos' // waits 15ms for the servo to reach the position
  for(pos = 180; pos>=1; pos-=1) {
    servo.write(pos); delay(15);

  }


  delay(5000); run();

}



// --------------------------------------------------------------------------- Loop
void run() {


   for(int i = 0; i < 360; i++){
     drive_forward(10);
     turn_right(4);
   }

   drive_forward(100);

   for(int i = 0; i < 360; i++){
     drive_forward(9);
     turn_left(3);
   }


   motor_stop();
}


void loop(){
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long Duration = pulseIn(ECHO_PIN,HIGH);

  long inches = calculate_inches(Duration);

  Serial.print("Distance = "); Serial.print(inches); Serial.println(" inches");
}



// --------------------------------------------------------------------------- Drive


void motor_stop(){
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], LOW);

  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], LOW);
  delay(25);
}


void drive_forward(int seconds){
  digitalWrite(motor_left[0], HIGH);
  digitalWrite(motor_left[1], LOW);

  digitalWrite(motor_right[0], HIGH);
  digitalWrite(motor_right[1], LOW);
  delay(seconds);
}


void drive_backward(int seconds){
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], HIGH);

  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], HIGH);
  delay(seconds);
}


void turn_left(int seconds){
  digitalWrite(motor_left[0], LOW);
  digitalWrite(motor_left[1], HIGH);

  digitalWrite(motor_right[0], HIGH);
  digitalWrite(motor_right[1], LOW);
  delay(seconds);
}


void turn_right(int seconds){
  digitalWrite(motor_left[0], HIGH);
  digitalWrite(motor_left[1], LOW);

  digitalWrite(motor_right[0], LOW);
  digitalWrite(motor_right[1], HIGH);

  delay(seconds);
}


long calculate_inches(long time){
  return time / 74 / 2;
}
