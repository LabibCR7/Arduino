#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      7

// Create NeoPixel object
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();      // Initialize NeoPixel strip
  strip.show();       // Turn OFF all pixels initially
}

void loop() {
  colorWipe(strip.Color(255, 0, 0), 50);   // Red
  colorWipe(strip.Color(0, 255, 0), 50);   // Green
  colorWipe(strip.Color(0, 0, 255), 50);   // Blue

  theaterChase(strip.Color(127, 127, 127), 50);  // White theater chase

  rainbow(20);                  // Rainbow scroll
  rainbowCycle(20);             // Rainbow cycle (5 cycles)
  theaterChaseRainbow(50);      // Theater chase with rainbow colors
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

// Theater-style crawling lights.
void theaterChase(uint32_t color, int wait) {
  for (int a = 0; a < 10; a++) {
    for (int b = 0; b < 3; b++) {
      strip.clear();
      for (int c = b; c < strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color);
      }
      strip.show();
      delay(wait);
    }
  }
}

// Rainbow wheel for full scroll
void rainbow(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}

// Rainbow cycle across all pixels
void rainbowCycle(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show();
    delay(wait);
  }
}

// Theater-style rainbow chase
void theaterChaseRainbow(int wait) {
  for (int a = 0; a < 30; a++) {
    for (int b = 0; b < 3; b++) {
      strip.clear();
      for (int c = b; c < strip.numPixels(); c += 3) {
        int hue = (c * 65536L / strip.numPixels()) + (a * 256);
        strip.setPixelColor(c, strip.gamma32(strip.ColorHSV(hue)));
      }
      strip.show();
      delay(w
