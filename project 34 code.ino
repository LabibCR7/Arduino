// Define pin numbers
int pirPin = 13;         // PIR sensor output pin connected to digital pin 13
int ledPin = 7;          // LED connected to digital pin 7

int pirState = LOW;      // Default state of PIR sensor
int val = 0;             // Variable to read PIR pin state

unsigned long calibrationTime = 30000;  // 30 seconds calibration
unsigned long lowIn;
unsigned long pause = 5000;             // 5 seconds before considering motion ended

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);           // Ensure PIR is LOW to begin
  Serial.begin(9600);

  Serial.print("Calibrating sensor");
  for (int i = 0; i < 30; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.println("Sensor active");
  delay(50);
}

void loop() {
  val = digitalRead(pirPin);           // Read PIR sensor

  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);        // Turn on LED
    if (pirState == LOW) {
      // Motion detected
      Serial.print("Motion detected at ");
      Serial.print(millis() / 1000);
      Serial.println(" sec");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);         // Turn off LED
    if (pirState == HIGH) {
      // Motion ended
      Serial.print("Motion ended at ");
      Serial.print(millis() / 1000);
      Serial.println(" sec");
      pirState = LOW;
    }
  }
}
