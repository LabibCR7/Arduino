#include <IRremote.h>
#include <Servo.h>

const int RECV_PIN = 11;   // IR receiver output pin
const int SERVO_PIN = 6;   // Servo control pin

IRrecv irrecv(RECV_PIN);
decode_results results;
Servo myServo;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();       // Start the IR receiver
  myServo.attach(SERVO_PIN); // Attach servo to pin
  myServo.write(90);         // Initial position
}

void loop() {
  if (irrecv.decode(&results)) {
    long code = results.value;
    Serial.print("IR Code: ");
    Serial.println(code, HEX); // Print received code in HEX format

    // Sample remote codes — replace with your actual values
    switch(code) {
      case 0xFFA25D: // "Power" button
        myServo.write(0);    // Move to 0 degrees
        break;
      case 0xFFE21D: // "Func/Stop" button
        myServo.write(90);   // Move to 90 degrees
        break;
      case 0xFF629D: // "Play/Pause" button
        myServo.write(180);  // Move to 180 degrees
        break;
    }

    irrecv.resume(); // Ready to receive the next code
  }
}
