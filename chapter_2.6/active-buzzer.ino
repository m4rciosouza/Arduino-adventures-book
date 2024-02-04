// Pin for the potentiometer
int potPin = A0;

void setup() {
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the potentiometer
  int potValue = analogRead(potPin);

  // Print the value to the serial monitor
  Serial.print("Potentiometer Value: ");
  Serial.println(potValue);

  // Add a small delay to avoid overwhelming
  // the serial monitor
  delay(500);
}