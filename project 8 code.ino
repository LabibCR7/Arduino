#include <Keypad.h>

// Define number of rows and columns
const byte ROWS = 4; 
const byte COLS = 4; 

// Define the keymap layout
char keys[ROWS][COLS] = {
  {'1','2','3','A'},   // A = +
  {'4','5','6','B'},   // B = -
  {'7','8','9','C'},   // C = *
  {'*','0','#','D'}    // D = /
};

// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins
byte rowPins[ROWS] = {9, 8, 7, 6};

// Connect keypad COL0, COL1, COL2 and COL3 to these Arduino pins
byte colPins[COLS] = {5, 4, 3, 2};

// Create the Keypad object
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // Start serial communication at 9600 baud
  Serial.println("Keypad is ready. Press a key:");
}

void loop() {
  char key = keypad.getKey(); // Read the key

  if (key) { // If a key is pressed
    Serial.print("Key Pressed: ");
    Serial.println(key); // Print the key to Serial Monitor
  }
}
