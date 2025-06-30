#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Resistor values for voltage divider
float R1 = 1000000.0; // 1 MΩ
float R2 = 10000.0;   // 10 kΩ

// Variables to hold the calculated voltage
float inputVoltage = 0.0;
float temp = 0.0;
int analogValue = 0;

void setup() {
  Serial.begin(9600);         // Initialize serial monitor (optional)
  lcd.begin(16, 2);           // Initialize 16x2 LCD
  lcd.print("Digital Voltmeter");
}

void loop() {
  analogValue = analogRead(A0); // Read analog value from pin A0

  // Convert analog value to voltage (based on 5V reference and 10-bit ADC)
  temp = (analogValue * 5.0) / 1024.0;

  // Reverse the voltage divider calculation to get input voltage
  inputVoltage = temp / (R2 / (R1 + R2));

  lcd.setCursor(0, 1); // Move to second line of LCD

  // Display voltage
  if (inputVoltage < 0.1) {
    lcd.print("Voltage = 0.00V   ");
  } else {
    lcd.print("Voltage = ");
    lcd.print(inputVoltage, 2); // Display 2 decimal places
    lcd.print("V  ");
  }

  // Also print to Serial Monitor (optional)
  Serial.print("Voltage = ");
  Serial.print(inputVoltage, 2);
  Serial.println(" V");

  delay(1000); // Wait for 1 second before next reading
}
