// Define variables for RGB LED pins
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// Define variable for potentiometer pin
int potPin = A0;

void setup() {
  // Set RGB LED pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Read potentiometer value
  int potValue = analogRead(potPin);

  // Map potentiometer value to the
  // range 0-255 for RGB colours
  int colorValue = map(potValue, 0, 1023, 0, 255);

  // Set RGB LED colours based on potentiometer value
  analogWrite(redPin, colorValue);
  // Invert value for smooth colour transition
  analogWrite(greenPin, 255 - colorValue);
  // Create a more balanced colour spectrum
  analogWrite(bluePin, 128 - abs(colorValue - 128));

  // Small delay for smooth transitions
  delay(10);
}