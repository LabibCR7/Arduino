// Define sensor pin
const int sensorPin = A0;  // Photodiode connected to A0
int sensorValue = 0;       // Variable to store analog reading

void setup() {
  Serial.begin(9600);       // Start Serial Monitor
  pinMode(sensorPin, INPUT); // Define pin as input
}

void loop() {
  sensorValue = analogRead(sensorPin);  // Read light level
  Serial.print("Light Intensity: ");
  Serial.println(sensorValue);          // Print value to Serial Monitor

  delay(500);  // Delay for readability
}
