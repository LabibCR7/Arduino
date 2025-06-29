#include <Adafruit_NeoPixel.h>

#define PIN 6         // Data pin connected to NeoPixels
#define NUMPIXELS 8   // Change based on your strip or ring (e.g., 8, 16, 24, 60, etc.)

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin(); // Initialize NeoPixel strip
  pixels.show();  // Turn off all pixels initially
}

void loop() {
  // Red
  setAllPixels(255, 0, 0);
  delay(1000);
  
  // Green
  setAllPixels(0, 255, 0);
  delay(1000);

  // Blue
  setAllPixels(0, 0, 255);
  delay(1000);

  // White
  setAllPixels(255, 255, 255);
  delay(1000);

  // Off
  setAllPixels(0, 0, 0);
  delay(1000);
}

void setAllPixels(uint8_t red, uint8_t green, uint8_t blue) {
  for(int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(red, green, blue));
  }
  pixels.show();
}
