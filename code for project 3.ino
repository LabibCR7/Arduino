int sensorValue = 0;        // Variable to store LDR reading
const int ldrPin = A0;      // LDR connected to analog pin A0
const int ledPin = 9;       // LED (and multimeter) connected to digital pin 9

void setup() {
  pinMode(ldrPin, INPUT);         // LDR as input
  pinMode(ledPin, OUTPUT);        // LED as output
  Serial.begin(9600);             // Start serial communication for monitoring
}

void loop() {
  sensorValue = analogRead(ldrPin);         // Read light intensity from LDR (0–1023)
  Serial.print("Light Intensity: ");
  Serial.println(sensorValue);              // Print the sensor value

  analogWrite(ledPin, sensorValue / 4);     // Convert 0–1023 to 0–255 for PWM output

  delay(100);     // Delay for 100 milliseconds before next reading
}
