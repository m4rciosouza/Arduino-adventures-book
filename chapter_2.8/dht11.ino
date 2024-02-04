// Pin for the photoresistor
int photoresistorPin = A0;

void setup() {
  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the photoresistor
  int photoresistorValue = analogRead(photoresistorPin);

  // Print the value to the serial monitor
  Serial.print("Photoresistor Value: ");
  Serial.println(photoresistorValue);

  // Add a small delay to avoid overwhelming
  // the serial monitor
  delay(500);
}