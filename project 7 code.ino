#include <Wire.h>
#include <LiquidCrystal.h>
#include <Keypad.h>

// LCD pin configuration
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Keypad configuration
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},  // A = +
  {'4', '5', '6', 'B'},  // B = -
  {'7', '8', '9', 'C'},  // C = *
  {'*', '0', '#', 'D'}   // * = Clear, # = =, D = /
};
byte rowPins[ROWS] = {7, 6, 5, 4};     // Connect to the row pins of the keypad
byte colPins[COLS] = {3, 2, 1, 0};     // Connect to the column pins

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Variables for calculation
long first = 0, second = 0;
float total = 0;
char operation = '\0';
bool enteringSecond = false;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Calculator");
  delay(2000);
  lcd.clear();
  lcd.print("Enter Numbers:");
  delay(2000);
  lcd.clear();
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    // If key is a digit
    if (customKey >= '0' && customKey <= '9') {
      int digit = customKey - '0';
      if (!enteringSecond) {
        first = first * 10 + digit;
        lcd.setCursor(0, 0);
        lcd.print(first);
      } else {
        second = second * 10 + digit;
        lcd.setCursor(0, 1);
        lcd.print(second);
      }
    }

    // If key is an operation
    else if (customKey == 'A' || customKey == 'B' || customKey == 'C' || customKey == 'D') {
      if (total != 0) {
        first = total;
        second = 0;
        total = 0;
      }
      enteringSecond = true;
      operation = customKey;
      lcd.setCursor(6, 0);
      lcd.print(getOperationSymbol(operation));
    }

    // If key is '='
    else if (customKey == '#') {
      lcd.setCursor(0, 1);

      switch (operation) {
        case 'A': // Addition
          total = first + second;
          break;
        case 'B': // Subtraction
          total = first - second;
          break;
        case 'C': // Multiplication
          total = first * second;
          break;
        case 'D': // Division
          if (second == 0) {
            lcd.clear();
            lcd.print("Invalid (÷0)");
            delay(2000);
            clearAll();
            return;
          } else {
            total = (float)first / second;
          }
          break;
        default:
          lcd.print("No Operation");
          delay(2000);
          clearAll();
          return;
      }

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Result:");
      lcd.setCursor(0, 1);
      lcd.print(total, 2); // Show two decimal places

      // Reset for next calculation
      first = 0;
      second = 0;
      operation = '\0';
      enteringSecond = false;
    }

    // If key is '*' → Clear
    else if (customKey == '*') {
      clearAll();
      lcd.print("Cleared");
      delay(1000);
      lcd.clear();
    }
  }
}

// Utility: Convert operation char to symbol
char getOperationSymbol(char op) {
  switch (op) {
    case 'A': return '+';
    case 'B': return '-';
    case 'C': return '*';
    case 'D': return '/';
    default: return '?';
  }
}

// Utility: Clear all data
void clearAll() {
  lcd.clear();
  first = 0;
  second = 0;
  total = 0;
  operation = '\0';
  enteringSecond = false;
}
