// Pin for the transistor base
int transistorPin = 9;

void setup() {
  // Set the transistor pin as an output
  pinMode(transistorPin, OUTPUT);
}

void loop() {
  // Turn on the motor
  digitalWrite(transistorPin, HIGH);
  delay(2000);  // Run for 2 seconds

  // Turn off the motor
  digitalWrite(transistorPin, LOW);
  delay(1000);  // Pause for 1 second
}