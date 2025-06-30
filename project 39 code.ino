// Pin configuration
int pot = A5; // Potentiometer connected to analog pin A5
int value = 0; // Variable to store potentiometer value

// LED pins
int led1 = 8;   // Green LED 1
int led2 = 9;   // Green LED 2
int led3 = 10;  // Yellow LED 1
int led4 = 11;  // Yellow LED 2
int led5 = 12;  // Red LED 1
int led6 = 13;  // Red LED 2

void setup() {
  Serial.begin(9600); // Start serial communication

  // Define LED pins as OUTPUT
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  // Optional: define potentiometer pin as INPUT (not strictly necessary)
  pinMode(pot, INPUT);
}

void loop() {
  value = analogRead(pot); // Read potentiometer value (0–1023)
  Serial.println(value);   // Print value to serial monitor
  delay(100);              // Short delay for readability

  // Turn off all LEDs initially
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);

  // Pattern logic based on potentiometer value
  if (value > 0 && value <= 250) {
    // Light up green LEDs
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else if (value > 250 && value <= 500) {
    // Light up yellow LEDs
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
  else if (value > 500) {
    // Light up red LEDs
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
}
