

//Libraries
#include <AFMotor.h>

//Objects
AF_DCMotor motorRight(1, MOTOR12_64KHZ); // create motor #1, 64KHz pwm
AF_DCMotor motorLeft(3, MOTOR12_64KHZ);  // create motor #3, 64KHz pwm

//Constants and variable
char dataIn = 'S';
char determinant;
char det;
int vel = 0; //Bluetooth Stuff


void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  
  //Initalization messages
  Serial.println("ArduinoBymyself - ROVERBot");
  Serial.println("     AF Motor test!");
  
  //turn off motors
  motorRight.setSpeed(0);
  motorLeft.setSpeed(0);
  motorRight.run(RELEASE);
  motorLeft.run(RELEASE);
  
  

}

void loop() {
  det = check(); //call check() subrotine to get the serial code
  
  //serial code analysis
  switch (det){
    case 'F': // F, move forward
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    det = check();
    break;
    
    case 'B': // B, move back
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel);
    motorRight.run(BACKWARD);      
    motorLeft.run(BACKWARD);
    det = check();
    break;
    
    case 'L':// L, move wheels left
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel/4);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    det = check();
    break;
    
    case 'R': // R, move wheels right
    motorRight.setSpeed(vel/4);
    motorLeft.setSpeed(vel);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    det = check();
    break;
    
    case 'I': // I, turn right forward
    motorRight.setSpeed(vel/2);
    motorLeft.setSpeed(vel);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    det = check();
    break;
    
    case 'J': // J, turn right back
    motorRight.setSpeed(vel/2);
    motorLeft.setSpeed(vel);  
    motorRight.run(BACKWARD);     
    motorLeft.run(BACKWARD);
    det = check();
    break;
    
    case 'G': // G, turn left forward
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel/2);
    motorRight.run(FORWARD);      
    motorLeft.run(FORWARD);
    det = check();
    break;
    
    case 'H': // H, turn left back
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel/2);
    motorRight.run(BACKWARD);     
    motorLeft.run(BACKWARD);
    det = check();
    break;
    
    case 'S': // S, stop
    motorRight.setSpeed(vel);
    motorLeft.setSpeed(vel);
    motorRight.run(RELEASE);      
    motorLeft.run(RELEASE);
    det = check();
    break;
    
    
    
  }
}

//get bluetooth code received from serial port
int check(){
  if (Serial.available() > 0){// if there is valid data in the serial port
    dataIn = Serial.read();// stores data into a varialbe
    
    //check the code
    if (dataIn == 'F'){//Forward
      determinant = 'F';
    }
    else if (dataIn == 'B'){//Backward
      determinant = 'B';
    }
    else if (dataIn == 'L'){//Left
      determinant = 'L';
    }
    else if (dataIn == 'R'){//Right
      determinant = 'R';
    }
    else if (dataIn == 'I'){//Froward Right
      determinant = 'I';
    }
    else if (dataIn == 'J'){//Backward Right
      determinant = 'J';
    }
    else if (dataIn == 'G'){//Forward Left
      determinant = 'G';
    }    
    else if (dataIn == 'H'){//Backward Left
      determinant = 'H';
    }
    else if (dataIn == 'S'){//Stop
      determinant = 'S';
    }
    else if (dataIn == '0'){//Speed 0
      vel = 0;
    }
    else if (dataIn == '1'){//Speed 25
      vel = 25;
    }
    else if (dataIn == '2'){//Speed 50
      vel = 50;
    }
    else if (dataIn == '3'){//Speed 75
      vel = 75;
    }
    else if (dataIn == '4'){//Speed 100
      vel = 100;
    }
    else if (dataIn == '5'){//Speed 125
      vel = 125;
    }
    else if (dataIn == '6'){//Speed 150
      vel = 150;
    }
    else if (dataIn == '7'){//Speed 175
      vel = 175;
    }
    else if (dataIn == '8'){//Speed 200
      vel = 200;
    }
    else if (dataIn == '9'){//Speed 225
      vel = 225;
    }
    else if (dataIn == 'q'){//Speed 255
      vel = 255;
    }
    else if (dataIn == 'U'){//Back Lights On
      determinant = 'U';
    }
    else if (dataIn == 'u'){//Back Lights Off
      determinant = 'u';
    }
    else if (dataIn == 'W'){//Front Lights On
      determinant = 'W';
    }
    else if (dataIn == 'w'){//Front Lights Off
      determinant = 'w';
    }
    else if (dataIn == 'V'){//Horn On
      determinant = 'V';
    }
    else if (dataIn == 'v'){//Horn Off
      determinant = 'v';
    }
    else if (dataIn == 'X'){//Extra On
      determinant = 'X';
    }
    else if (dataIn == 'x'){//Extra Off
      determinant = 'x';
    }
  }
  return determinant;
}
