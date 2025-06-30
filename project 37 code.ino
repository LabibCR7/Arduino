#include <Servo.h>
#include <LiquidCrystal.h>

// Initialize LCD with pins: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Servo motor
Servo gateServo;

// Define IR sensor pins
const int entryIR = 7;
const int exitIR = 6;

// Variables for parking status
bool slotOccupied = false;

// Servo angles
int openAngle = 90;
int closedAngle = 0;

// Pin for the servo motor
int servoPin = 9;

void setup() {
  // Setup IR sensor pins
  pinMode(entryIR, INPUT);
  pinMode(exitIR, INPUT);

  // Setup LCD
  lcd.begin(16, 2);
  lcd.print("Smart Parking");
  delay(2000);
  lcd.clear();

  // Attach servo
  gateServo.attach(servoPin);
  gateServo.write(closedAngle);

  // Display initial status
  lcd.print("Slot: Available");
}

void loop() {
  int entryStatus = digitalRead(entryIR);
  int exitStatus = digitalRead(exitIR);

  // If car arrives at entry
  if (entryStatus == LOW && !slotOccupied) {
    lcd.clear();
    lcd.print("Car Entering...");
    gateServo.write(openAngle);
    delay(2000);
    gateServo.write(closedAngle);
    slotOccupied = true;
    lcd.clear();
    lcd.print("Slot: Occupied");
    delay(1000);
  }

  // If car leaves
  if (exitStatus == LOW && slotOccupied) {
    lcd.clear();
    lcd.print("Car Exiting...");
    gateServo.write(openAngle);
    delay(2000);
    gateServo.write(closedAngle);
    slotOccupied = false;
    lcd.clear();
    lcd.print("Slot: Available");
    delay(1000);
  }
}
