// Frequencies for the musical notes (in Hz)
#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 329
#define NOTE_F 349
#define NOTE_G 392
#define NOTE_A 440
#define NOTE_B 494

// Pin definitions for buttons
const int cKey = 2;
const int dKey = 4;
const int eKey = 6;
const int fKey = 7;
const int gKey = 9;
const int aKey = 11;
const int bKey = 12;

// Buzzer pin
const int buzzer = 13;

void setup() {
  // Set all key pins as input with internal pull-up resistors
  pinMode(cKey, INPUT_PULLUP);
  pinMode(dKey, INPUT_PULLUP);
  pinMode(eKey, INPUT_PULLUP);
  pinMode(fKey, INPUT_PULLUP);
  pinMode(gKey, INPUT_PULLUP);
  pinMode(aKey, INPUT_PULLUP);
  pinMode(bKey, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
}

void loop() {
  if (digitalRead(cKey) == LOW) {
    tone(buzzer, NOTE_C);
  } else if (digitalRead(dKey) == LOW) {
    tone(buzzer, NOTE_D);
  } else if (digitalRead(eKey) == LOW) {
    tone(buzzer, NOTE_E);
  } else if (digitalRead(fKey) == LOW) {
    tone(buzzer, NOTE_F);
  } else if (digitalRead(gKey) == LOW) {
    tone(buzzer, NOTE_G);
  } else if (digitalRead(aKey) == LOW) {
    tone(buzzer, NOTE_A);
  } else if (digitalRead(bKey) == LOW) {
    tone(buzzer, NOTE_B);
  } else {
    noTone(buzzer);  // Stop sound if no key is pressed
  }
}
