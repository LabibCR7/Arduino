// Define pin for the buzzer
const int buzzerPin = 8;

// Define pins for buttons
const int buttonPins[] = {2, 3, 4, 5, 6, 7}; // Connect 6 push buttons

// Define frequencies for notes (C D E F G A)
const int noteFrequencies[] = {
  262,  // C4
  294,  // D4
  330,  // E4
  349,  // F4
  392,  // G4
  440   // A4
};

void setup() {
  // Set button pins as input
  for (int i = 0; i < 6; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Use internal pull-up resistors
  }

  pinMode(buzzerPin, OUTPUT); // Buzzer pin as output
}

void loop() {
  bool notePlayed = false;

  // Check each button
  for (int i = 0; i < 6; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { // Button pressed (active LOW)
      tone(buzzerPin, noteFrequencies[i]);   // Play corresponding note
      notePlayed = true;
      break; // Only one note at a time
    }
  }

  // If no button is pressed, stop the tone
  if (!notePlayed) {
    noTone(buzzerPin);
  }
}
