/* ArduinoDCC
 
 Arduino sketch for a DCC controller.

 04/01/2020
  Initial commit.
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards


typedef struct servos {
   int position;
   int angle;
} ServoType;

int pos = 80;    // variable to store the servo position
ServoType servoType;
int minAng = 70; 
int maxAng = 160;
int stpAng = 5;

void setup() {
  Serial.begin(115200);
  pinMode(45,INPUT);
  myservo.attach(9); // attaches the servo on pin 9 to the servo object
  

  servoType.position = 0;
  servoType.angle = minAng;
}

void sweepServo()
{
  
  if(servoType.position == 0)
  {
    if(servoType.angle != minAng)
    {
      servoType.angle -= stpAng;
      if(servoType.angle <= minAng)
      {
          servoType.angle = minAng;
      }
    }
    myservo.write(servoType.angle);              // tell servo to go to position in variable 'pos'    
  }

  if(servoType.position == 1)
  {
    if(servoType.angle != maxAng)
    {
      servoType.angle += stpAng;
      if(servoType.angle >= maxAng)
      {
          servoType.angle = maxAng;
      }
      
    }
    myservo.write(servoType.angle);              // tell servo to go to position in variable 'pos'    
  }
  
}

void loop() {
  while (Serial.available() > 0) {
    int pos = Serial.parseInt();
    if (Serial.read() == '\n') {
      servoType.position = pos;  
    }
  }

  //Position servos
  sweepServo();

  delay(5);                       // waits 15ms for the servo to reach the position
  
  Serial.println(digitalRead(45));
  
}
