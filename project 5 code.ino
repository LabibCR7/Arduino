// Define pin for TMP36 sensor
int tempPin = A0;

// Variables to store values
float tempCelsius;
float tempFahrenheit;
int analogReading;
float voltage;

void setup() {
  Serial.begin(9600);           // Start serial communication
  pinMode(tempPin, INPUT);      // Set temperature sensor pin as input
}

void loop() {
  // Step 1: Read analog value from sensor
  analogReading = analogRead(tempPin);

  // Step 2: Convert analog reading to voltage
  voltage = analogReading * 5.0 / 1024.0;

  // Step 3: Convert voltage to Celsius temperature
  // TMP36 gives 0.5V at 0°C and increases by 10mV/°C
  tempCelsius = (voltage - 0.5) * 100.0;

  // Step 4: Convert Celsius to Fahrenheit
  tempFahrenheit = (tempCelsius * 9.0 / 5.0) + 32.0;

  // Step 5: Display results in Serial Monitor
  Serial.print("Analog Reading: ");
  Serial.println(analogReading);

  Serial.print("Voltage (V): ");
  Serial.println(voltage);

  Serial.print("Temperature: ");
  Serial.print(tempCelsius);
  Serial.print(" °C, ");

  Serial.print(tempFahrenheit);
  Serial.println(" °F");

  Serial.println("-----------------------------");

  delay(3000);  // Wait for 3 seconds before next reading
}
