// Pin definitions
const int potPin = A0;     // Potentiometer connected to A0
const int ledPin = 9;      // LED connected to PWM pin 9

int potValue = 0;          // Stores analog reading
int brightness = 0;        // Stores mapped brightness (0-255)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // To monitor potentiometer values
}

void loop() {
  // Read analog value from potentiometer
  potValue = analogRead(potPin);        // 0 - 1023
  brightness = map(potValue, 0, 1023, 0, 255);  // Scale to 0 - 255

  // Write PWM signal to LED
  analogWrite(ledPin, brightness);

  // Debug output to serial monitor
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Brightness: ");
  Serial.println(brightness);

  delay(100); // Short delay for stability
}
