// Automatic Hand Sanitizer Dispenser using Arduino and Ultrasonic Sensor

#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;
long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  Serial.begin(9600);
  myServo.write(0);  // Servo in resting position
}

void loop() {
  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo duration
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;  // Convert to cm

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 10) {
    myServo.write(90); // Dispense hand sanitizer
    delay(1000);        // Wait for dispensing
    myServo.write(0);   // Reset servo position
    delay(2000);        // Wait before next detection
  }
  delay(100);
}
