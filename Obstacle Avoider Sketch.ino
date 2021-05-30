

#include <AFMotor.h>
#define trigPin 14 // define the pins of your sensor
#define echoPin 15 

int vel = 255; // Speed of the robot

//Objects
AF_DCMotor motorRight(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorLeft(3, MOTOR12_64KHZ);  // create motor #3, 64KHz pwm

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)  

  //Initalization messages
  Serial.println(" Mr.robot");
  Serial.println(" Reday for working!");
  
  //turn off motors
  motorRight.setSpeed(0);
  motorLeft.setSpeed(0);
  motorRight.run(RELEASE);
  motorLeft.run(RELEASE);
}

void loop() {
 //obstacle avoider robot
  
   motorRight.setSpeed(vel); //set the speed of the motors, between 0-255
   motorLeft.setSpeed (vel);  
 
  long duration, distance; // start the scan
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  if (distance < 25)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
Serial.println ("Close Obstacle detected!" );
Serial.println ("Obstacle Details:");
Serial.print ("Distance From Robot is " );
Serial.print ( distance);
Serial.print ( " CM!");// print out the distance in centimeters.

Serial.println (" The obstacle is declared a threat due to close distance. ");
Serial.println (" Turning !");
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel); 
    motorLeft.run(BACKWARD);  // Turn as long as there's an obstacle ahead.
    motorRight.run (FORWARD);

}
  else {
   Serial.println ("No obstacle detected. going forward");
   delay (15);
   motorRight.setSpeed(vel);
   motorLeft.setSpeed(vel);
   motorRight.run(FORWARD); //if there's no obstacle ahead, Go Forward! 
   motorLeft.run(FORWARD);  

    } 
  } 
