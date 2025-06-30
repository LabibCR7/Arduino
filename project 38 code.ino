// The setup function runs once when the Arduino is powered on or reset
void setup() {
  // Initialize digital pin 13 (LED_BUILTIN) as an output pin
  pinMode(LED_BUILTIN, OUTPUT);
}

// The loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on (HIGH = 5V)
  delay(1000);                      // Wait for 1 second (1000 ms)

  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off (LOW = 0V)
  delay(1000);                      // Wait for 1 second
}
