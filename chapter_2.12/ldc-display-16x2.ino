// Pin for the photoresistor
int photoresistorPin = A0;

// Pins for the LEDs
int ledPin1 = 2;
int ledPin2 = 3;

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Set the LED pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Read the analog value from the photoresistor
  int lightLevel = analogRead(photoresistorPin);

  // Print the light level to the serial monitor
  Serial.print("Light Level: ");
  Serial.println(lightLevel);

  // Check if it's dark (you may
  // need to adjust the threshold)
  if (lightLevel > 500) {
    // Turn on the LEDs
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
  } else {
    // Turn off the LEDs
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  delay(1000);  // Delay for 1 second
}