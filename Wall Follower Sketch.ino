

#include <AFMotor.h>
#define trigPin 14 // define the pins of your sensor
#define echoPin 15 

int vel = 255; // Speed of the robot

			   //Objects
AF_DCMotor motorRight(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorLeft(3, MOTOR12_64KHZ);  // create motor #3, 64KHz pwm

void setup()
{
	Serial.begin(9600); // set up Serial library at 9600 bps

	pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
	pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)  

							//Initalization messages
	Serial.println(" Mr.robot");
	Serial.println(" Reday for working!");

	//turn off motors
	motorRight.setSpeed(0);
	motorLeft.setSpeed(0);//set speed to 0
	motorRight.run(RELEASE);
	motorLeft.run(RELEASE);
}

void loop()
{

	//for wall follower robot.
	motorRight.setSpeed(vel); //set the speed of the motors, between 0-255
	motorLeft.setSpeed(vel);

	long duration, distance; // start the scan
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2); // delays are required for a succesful sensor operation.
	digitalWrite(trigPin, HIGH);

	delayMicroseconds(10); //this delay is required as well!
	digitalWrite(trigPin, LOW);
	duration = pulseIn(echoPin, HIGH);
	distance = (duration / 2) / 29.1;// convert the distance to centimeters.
	if (distance < 30)/*The distance that need to to keep with the wall */
	{
		Serial.println("Wall is ditected!");
		Serial.println(" Started following the wall ");
		Serial.println(" Turning !");
		motorRight.setSpeed(vel);
		motorLeft.setSpeed(0);
		motorRight.run(FORWARD);
		motorLeft.run(RELEASE);
		delay(500); // wait for a second
	}

	else
	{
		Serial.println("No Wall detected. turning round");
		delay(15);
		motorRight.setSpeed(0);
		motorLeft.setSpeed(vel);
		motorRight.run(RELEASE);
		motorLeft.run(FORWARD);
	}
}
