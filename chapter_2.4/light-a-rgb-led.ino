// Pin for the push button
int buttonPin = 2;

void setup() {
  // Set the push button pin as an input
  pinMode(buttonPin, INPUT_PULLUP);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the state of the push button
  int buttonState = digitalRead(buttonPin);

  // Check if the button is pressed (LOW)
  if (buttonState == LOW) {
    Serial.println("Button Pressed!");
    // Add a small delay to avoid
    // multiple readings for a single press
    delay(500);
  }
}
