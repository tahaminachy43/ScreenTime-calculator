#include <Servo.h>

Servo myServo; 

int servoPin = 9;

void setup() {
  myServo.attach(servoPin); 
  Serial.begin(9600);
  myServo.write(75);
  Serial.println("Enter an age (18, 30, 50):");
}

void loop() {
  if (Serial.available() > 0) {
    int age = Serial.parseInt(); 

    if (age == 18 || age == 30 || age == 50) {
      Serial.print("Received input: ");
      Serial.println(age);

      int delayTime;
      if (age == 18) {
        delayTime = 30000; // 30 seconds
      } else if (age == 30) {
        delayTime = 20000; // 20 seconds
      } else if (age == 50) {
        delayTime = 10000; // 10 seconds
      }

      
      for (int angle = 75; angle <= 90; angle++) {
        myServo.write(angle); // Set the servo position
        Serial.print("Angle: ");
        Serial.println(angle);
        delay(150); 
      }
      delay(delayTime);

      
      for (int angle = 90; angle >= 75; angle--) {
        myServo.write(angle); // Set the servo position
        delay(150); 
      }
      delay(10000);

      // Additional sweep from 30 to 100 degrees with a fixed 30-second delay per step
      // for (int angle = 30; angle <= 100; angle++) {
      //   myServo.write(angle); // Set the servo position
      //   Serial.print("Angle: ");
      //   Serial.println(angle);
      //   delay(30000); // 30-second delay for each step
      // }
      myServo.write(130);
      delay(30000);
      myServo.write(70);

      Serial.println("Enter another age (18, 30, 50):");
    } else {
      Serial.println("Invalid input. Please enter 18, 30, or 50:");
    }
  }
}

