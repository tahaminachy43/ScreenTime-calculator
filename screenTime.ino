#include <Servo.h>

Servo myServo; // Create a servo object to control a servo motor

int servoPin = 9; // Define the pin to which the servo is connected

void setup() {
  myServo.attach(servoPin); // Attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  myServo.write(75);
  Serial.println("Enter an age (18, 30, 50):");
}

void loop() {
  if (Serial.available() > 0) {
    int age = Serial.parseInt(); // Read the user input from the Serial Monitor

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

      // Sweep the servo from 60 to 80 degrees in steps of 1 degree with age-specific delay
      for (int angle = 75; angle <= 90; angle++) {
        myServo.write(angle); // Set the servo position
        Serial.print("Angle: ");
        Serial.println(angle);
        delay(150); // Wait for servo to reach the position based on age
      }
      delay(delayTime);

      // Sweep the servo from 80 to 60 degrees in steps of 1 degree with age-specific delay
      for (int angle = 90; angle >= 75; angle--) {
        myServo.write(angle); // Set the servo position
        delay(150); // Wait for servo to reach the position based on age
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

