#include <Servo.h>

// Define pins for ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;

// Define servo pin
const int servoPin = 6;

// Define distance threshold (in cm)
const int threshold = 10;

Servo dispenserServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  dispenserServo.attach(servoPin);
  dispenserServo.write(0);  // Initial position (no dispensing)
}

void loop() {
  // Measure distance
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // Convert to centimeters

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if hand is close enough
  if (distance > 0 && distance <= threshold) {
    // Dispense sanitizer
    dispenserServo.write(90);  // Move servo to press pump
    delay(1000);               // Hold for 1 second
    dispenserServo.write(0);   // Reset servo
    delay(2000);               // Cooldown delay
  }

  delay(200); // Short pause before next reading
}
