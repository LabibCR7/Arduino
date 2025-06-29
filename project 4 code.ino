#include <Keypad.h>

// Define password
String password = "1234";  // You can change this
String input = "";

// LED pins
const int redLED = 10;
const int greenLED = 11;

// Keypad configuration
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};    // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2};    // Connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  Serial.println("Enter Password:");
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.print(key);
    
    if (key == '#') {
      if (input == password) {
        Serial.println("\nAccess Granted");
        digitalWrite(greenLED, HIGH);
        digitalWrite(redLED, LOW);
        delay(3000);  // Keep green LED on for 3 seconds
        digitalWrite(greenLED, LOW);
      } else {
        Serial.println("\nAccess Denied");
        digitalWrite(redLED, HIGH);
        digitalWrite(greenLED, LOW);
        delay(3000);  // Keep red LED on for 3 seconds
        digitalWrite(redLED, LOW);
      }
      input = ""; // Clear input
    } 
    else if (key == '*') {
      input = ""; // Reset on '*'
      Serial.println("\nInput Cleared");
    } 
    else {
      input += key; // Append to input
    }
  }
}
