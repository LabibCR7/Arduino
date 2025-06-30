// TMP36 connected to A2 (PB4)
const int tempPin = A2;

// LEDs
const int whiteLED = 0;  // PB0
const int redLED   = 1;  // PB1
const int greenLED = 2;  // PB2
const int blueLED  = 3;  // PB3

void setup() {
  pinMode(whiteLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop() {
  int reading = analogRead(tempPin);
  float voltage = reading * (5.0 / 1024.0);
  float temperatureC = (voltage - 0.5) * 100.0;

  // Turn off all LEDs initially
  digitalWrite(whiteLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(blueLED, LOW);

  // Set LED based on temperature ranges
  if (temperatureC > 10 && temperatureC <= 15) {
    digitalWrite(whiteLED, HIGH);
  } else if (temperatureC > 15 && temperatureC <= 20) {
    digitalWrite(blueLED, HIGH);
  } else if (temperatureC > 20 && temperatureC <= 25) {
    digitalWrite(greenLED, HIGH);
  } else if (temperatureC > 25) {
    digitalWrite(redLED, HIGH);
  }

  delay(500); // Add blinking delay
}
