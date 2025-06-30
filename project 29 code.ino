void setup() {
  // Set pins 1 to 8 as OUTPUT
  for (int ledPin = 1; ledPin <= 8; ledPin++) {
    pinMode(ledPin, OUTPUT);
  }
}

void loop() {
  // Turn on LEDs one by one (flowing effect)
  for (int ledPin = 1; ledPin <= 8; ledPin++) {
    digitalWrite(ledPin, HIGH);  // Turn on LED
    delay(300);                  // Wait
  }

  // Turn off LEDs one by one (flowing off effect)
  for (int ledPin = 1; ledPin <= 8; ledPin++) {
    digitalWrite(ledPin, LOW);   // Turn off LED
    delay(300);                  // Wait
  }
}
