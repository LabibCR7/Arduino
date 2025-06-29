#include <IRremote.h>   // Include the IR remote library

const int recvPin = 12;           // IR sensor signal pin
IRrecv irrecv(recvPin);           // Create IR receiver object
decode_results results;           // Variable to store decoded IR values

const int bluePin = 2;            // Blue LED connected to pin 2
const int orangePin = 3;          // Orange LED connected to pin 3
const int greenPin = 4;           // Green LED connected to pin 4

void setup() {
  Serial.begin(9600);             // Start serial monitor
  irrecv.enableIRIn();            // Start the IR receiver
  pinMode(bluePin, OUTPUT);       // Set LED pins as output
  pinMode(orangePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    long int value = results.value;    // Store received value
    Serial.println(value);             // Print value to serial monitor

    switch (value) {
      // You MUST replace these hex values with the ones from your IR remote
      case 0xFFA25D:   // Button "1" → Turn ON Blue LED
        digitalWrite(bluePin, HIGH);
        break;
      case 0xFF629D:   // Button "2" → Turn OFF Blue LED
        digitalWrite(bluePin, LOW);
        break;
      case 0xFFE21D:   // Button "3" → Turn ON Orange LED
        digitalWrite(orangePin, HIGH);
        break;
      case 0xFF22DD:   // Button "4" → Turn OFF Orange LED
        digitalWrite(orangePin, LOW);
        break;
      case 0xFF02FD:   // Button "5" → Turn ON Green LED
        digitalWrite(greenPin, HIGH);
        break;
      case 0xFFC23D:   // Button "6" → Turn OFF Green LED
        digitalWrite(greenPin, LOW);
        break;
      default:
        // If other button pressed, do nothing
        break;
    }

    irrecv.resume();  // Receive the next value
    delay(10);        // Small delay to avoid bouncing
  }
}
