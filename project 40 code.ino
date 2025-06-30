#include <Servo.h>

// Create servo objects
Servo servoH; // Horizontal servo
Servo servoV; // Vertical servo

// Assign analog pins for LDRs
int ldrTopLeft = A0;
int ldrTopRight = A1;
int ldrBottomLeft = A2;
int ldrBottomRight = A3;

// Servo positions
int posH = 90;  // Initial horizontal position
int posV = 90;  // Initial vertical position

// Servo limits
int hMin = 0;
int hMax = 180;
int vMin = 45;
int vMax = 135;

// Tolerance for light intensity difference
int tolerance = 10;

void setup() {
  // Attach servos to pins
  servoH.attach(9);
  servoV.attach(10);

  // Move to initial position
  servoH.write(posH);
  servoV.write(posV);

  delay(2500); // Initial delay
  Serial.begin(9600);
}

void loop() {
  // Read light values from the LDRs
  int tl = analogRead(ldrTopLeft);
  int tr = analogRead(ldrTopRight);
  int bl = analogRead(ldrBottomLeft);
  int br = analogRead(ldrBottomRight);

  // Calculate average values
  int avgTop = (tl + tr) / 2;
  int avgBottom = (bl + br) / 2;
  int avgLeft = (tl + bl) / 2;
  int avgRight = (tr + br) / 2;

  int diffVertical = avgTop - avgBottom;
  int diffHorizontal = avgLeft - avgRight;

  Serial.print("Top: "); Serial.print(avgTop);
  Serial.print(" | Bottom: "); Serial.print(avgBottom);
  Serial.print(" | Left: "); Serial.print(avgLeft);
  Serial.print(" | Right: "); Serial.println(avgRight);

  // Adjust vertical servo
  if (abs(diffVertical) > tolerance) {
    if (diffVertical > 0) {
      posV = constrain(posV + 1, vMin, vMax);
    } else {
      posV = constrain(posV - 1, vMin, vMax);
    }
    servoV.write(posV);
  }

  // Adjust horizontal servo
  if (abs(diffHorizontal) > tolerance) {
    if (diffHorizontal > 0) {
      posH = constrain(posH + 1, hMin, hMax);
    } else {
      posH = constrain(posH - 1, hMin, hMax);
    }
    servoH.write(posH);
  }

  delay(10); // Small delay for smooth operation
}
