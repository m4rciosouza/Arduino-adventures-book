// Define LED pins
const int ledPins[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

// Define potentiometer pin
const int potPin = A0;

void setup() {
  // Set LED pins as OUTPUT
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Read potentiometer value
  int potValue = analogRead(potPin);

  // Map potentiometer value to the range 0-7 for LED control
  int ledLevel = map(potValue, 0, 1023, 0, 7);

  // Light up LEDs based on the potentiometer position
  for (int i = 0; i < 8; i++) {
    if (i <= ledLevel) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  // Small delay for smooth transitions
  delay(10);
}