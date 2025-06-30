// Define pins
const int redLED = 11;
const int yellowLED = 12;
const int greenLED = 13;
const int buttonPin = 2;

// Variable to hold current mode
int mode = 0;
int lastButtonState = 0;

void setup() {
  // Set LED pins as output
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  // Set button pin as input
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  // Detect rising edge of button press
  if (buttonState == HIGH && lastButtonState == LOW) {
    mode++;
    if (mode > 2) {
      mode = 0;
    }
    delay(200); // debounce delay
  }
  lastButtonState = buttonState;

  // Handle LED modes
  switch (mode) {
    case 0: // Red ON
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);
      break;
    case 1: // Yellow ON
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, LOW);
      break;
    case 2: // Green ON
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, HIGH);
      break;
  }
}
