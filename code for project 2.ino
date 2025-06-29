// Arduino Fire Alarm: Temperature + Gas sensors
const int gasPin = A0;       // Analog pin for gas sensor (AO)
const int tempPin = A1;      // Analog pin for LM35 temperature sensor
const int buzzerPin = 7;     // Digital pin for piezo buzzer
const int ledPin = 13;       // Digital pin for LED

void setup() {
  Serial.begin(9600);              // Initialize serial monitor
  pinMode(gasPin, INPUT);          // (analog pins are input by default)
  pinMode(tempPin, INPUT);
  pinMode(buzzerPin, OUTPUT);      // Buzzer output
  pinMode(ledPin, OUTPUT);         // LED output
}

void loop() {
  // Read raw analog values
  int gasVal = analogRead(gasPin);
  int tempRaw = analogRead(tempPin);
  
  // Convert LM35 reading to voltage (5V/1023 steps) and then to °C (10mV/°C)
  float voltage = tempRaw * (5.0 / 1024.0);    // Each unit ≈4.88mV:contentReference[oaicite:11]{index=11}
  float temperatureC = voltage * 100.0;        // LM35: 10mV per °C:contentReference[oaicite:12]{index=12}

  // Check thresholds and activate alarms
  if (temperatureC >= 80.0) {
    digitalWrite(ledPin, HIGH);  // Turn on LED if temp >= 80°C
  } else {
    digitalWrite(ledPin, LOW);
  }
  if (gasVal >= 100) {
    digitalWrite(buzzerPin, HIGH);  // Sound buzzer if gas threshold reached
  } else {
    digitalWrite(buzzerPin, LOW);
  }

  // Print readings to Serial Monitor
  Serial.print("Temperature (°C): ");
  Serial.print(temperatureC);
  Serial.print("\tGas sensor (A0): ");
  Serial.println(gasVal);
  delay(1000);  // Update once per second
}
