#include <LiquidCrystal.h>

// LCD pin connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tempPin = A0; // TMP36 Vout to A0

void setup() {
  lcd.begin(16, 2); // 16x2 LCD
  lcd.print("Today's Temp:");
  delay(1000);
}

void loop() {
  int rawValue = analogRead(tempPin);

  // Convert raw ADC to voltage
  float voltage = (rawValue / 1024.0) * 5.0;

  // TMP36: 10mV/°C with 500mV offset
  float tempC = (voltage - 0.5) * 100.0;
  float tempF = (tempC * 9.0 / 5.0) + 32.0;

  // Display on LCD
  lcd.setCursor(0, 1); // Start at 2nd row
  lcd.print("C:");
  lcd.print(tempC, 1); // 1 decimal place
  lcd.print(" F:");
  lcd.print(tempF, 1);

  delay(1000); // Update every second
}
