int ledPin = 11; // PWM pin connected to LED

void setup() {
  pinMode(ledPin, OUTPUT); // Set the pin as output
}

void loop() {
  // Increase brightness
  for (int a = 0; a <= 255; a++) {
    analogWrite(ledPin, a);  // Write PWM value
    delay(20);               // Smooth transition
  }

  // Decrease brightness
  for (int a = 255; a >= 0; a--) {
    analogWrite(ledPin, a);
    delay(20);
  }

  delay(200); // Short pause before the next cycle
}
