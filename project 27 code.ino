const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8}; // a to g
const int buttonPin = 9;

int diceNumbers[6][7] = {
  // a, b, c, d, e, f, g (0 = off, 1 = on)
  {1, 1, 1, 1, 1, 1, 0}, // 0 - actually not used
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}  // 6
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);
  randomSeed(analogRead(0)); // for randomness
}

void displayNumber(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], diceNumbers[num][i]);
  }
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    int number = random(1, 7); // 1 to 6
    displayNumber(number);
    delay(300); // debounce
    while (digitalRead(buttonPin) == LOW); // wait until released
  }
}
