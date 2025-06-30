// Define pins
const int pirPin = 8;
const int redPin = 3;
const int greenPin = 5;
const int bluePin = 6;
const int buzzerPin = 9;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int motionDetected = digitalRead(pirPin);
  
  if (motionDetected == HIGH) {
    Serial.println("Motion detected!");

    // Flash RGB Colors
    setColor(255, 0, 0);  // Red
    tone(buzzerPin, 1000); // Alarm sound
    delay(300);

    setColor(0, 255, 0);  // Green
    delay(300);

    setColor(0, 0, 255);  // Blue
    delay(300);

    setColor(255, 255, 0); // Yellow
    delay(300);

    setColor(255, 0, 255); // Magenta
    delay(300);

    setColor(0, 255, 255); // Cyan
    delay(300);

    noTone(buzzerPin); // Turn off buzzer
    setColor(0, 0, 0);  // LED off
  } 
  else {
    setColor(0, 0, 0);  // LED off
    noTone(buzzerPin); // Buzzer off
  }

  delay(100);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
