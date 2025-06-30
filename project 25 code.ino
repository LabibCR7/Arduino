#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD I2C address (you may need to scan your I2C address if unknown)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 0x27 is the typical I2C address

void setup() {
  lcd.begin(16, 2);       // Initialize the 16x2 LCD
  lcd.backlight();        // Turn on backlight
  lcd.setCursor(0, 0);    // Set cursor to first column, first row
  lcd.print("Hello, World!");
  lcd.setCursor(0, 1);    // Second line
  lcd.print("ATtiny85 LCD");
}

void loop() {
  // No updates in loop; static display
}
