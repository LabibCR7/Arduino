#include <Servo.h>         // Include Servo motor library

Servo myServo;             // Create a servo object
int position = 0;          // To store servo angle

void setup() {
  myServo.attach(7);       // Attach servo signal to pin 7
}

void loop() {
  // Move from 0° to 180°
  for (position = 0; position <= 180; position++) {
    myServo.write(position);     // Move servo to current position
    delay(15);                   // Delay for smooth motion (15ms)
  }

  delay(3000);  // Optional pause at 180°

  // Move from 180° back to 0°
  for (position = 180; position >= 0; position--) {
    myServo.write(position);     // Move servo back
    delay(15);
  }

  delay(3000);  // Optional pause at 0°
}
