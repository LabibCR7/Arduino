// Define pin connections
int pirPin = 2;        // PIR sensor output pin connected to digital pin 2
int ledPin = 13;       // LED connected to digital pin 13
int pirState = LOW;    // Variable to store PIR state
int val = 0;           // Variable to read the sensor status

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  pinMode(pirPin, INPUT);   // Set PIR sensor pin as input
  Serial.begin(9600);       // Start serial communication for debugging
}

void loop() {
  val = digitalRead(pirPin);  // Read PIR sensor output
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn ON LED
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);  // Turn OFF LED
    if (pirState == HIGH) {
      Serial.println("Motion ended.");
      pirState = LOW;
    }
  }
}
