const int ledPin = 0;     // PB0
const int tempPin = A1;   // PB2 (Analog input pin)

float realDegree = 0.0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(tempPin);
  
  // Convert analog value to voltage (0 - 5V)
  float voltage = sensorValue * (5.0 / 1024.0);
  
  // Convert voltage to temperature in Celsius
  float temperatureC = (voltage - 0.5) * 100;

  // Blink LED based on temperature range
  if (temperatureC < 0) {
    // Very low temperature: blink fast
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  else if (temperatureC >= 0 && temperatureC <= 50) {
    // Normal range: blink steadily
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
  }
  else if (temperatureC > 50 && temperatureC <= 95) {
    // Hot: blink slowly
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  else if (temperatureC > 100) {
    // Too hot: no blink (LED off)
    digitalWrite(ledPin, LOW);
  }
}
