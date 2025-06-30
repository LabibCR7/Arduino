int potPin = A0;     // Potentiometer is connected to analog pin A0
int ledPin = 9;      // LED is connected to PWM pin 9
int potValue = 0;    // Variable to store potentiometer value
int brightness = 0;  // Mapped brightness value (0–255)

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  Serial.begin(9600);       // Start serial monitor for debugging
}

void loop() {
  potValue = analogRead(potPin);             // Read the potentiometer (0–1023)
  brightness = map(potValue, 0, 1023, 0, 255); // Map to PWM range (0–255)
  analogWrite(ledPin, brightness);            // Set LED brightness
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(brightness);
  delay(100); // Small delay to stabilize readings
}
