// Pin for the active buzzer
int buzzerPin = 3;

void setup() {
  // Set the buzzer pin as an output
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Turn the buzzer on
  digitalWrite(buzzerPin, HIGH);
  delay(1000);  // Wait for 1 second

  // Turn the buzzer off
  digitalWrite(buzzerPin, LOW);
  delay(1000);  // Wait for 1 second
}
