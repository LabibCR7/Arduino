// RGB LED connected to digital pins
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// Function to set color
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);     // Set brightness of red
  analogWrite(greenPin, green); // Set brightness of green
  analogWrite(bluePin, blue);   // Set brightness of blue
}

void setup() {
  // Set the RGB pins as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);    // Red
  delay(1000);

  setColor(0, 255, 0);    // Green
  delay(1000);

  setColor(0, 0, 255);    // Blue
  delay(1000);

  setColor(255, 255, 0);  // Yellow (Red + Green)
  delay(1000);

  setColor(0, 255, 255);  // Cyan (Green + Blue)
  delay(1000);

  setColor(255, 0, 255);  // Magenta (Red + Blue)
  delay(1000);

  setColor(255, 255, 255); // White
  delay(1000);

  setColor(0, 0, 0);      // OFF (Black)
  delay(1000);
}
