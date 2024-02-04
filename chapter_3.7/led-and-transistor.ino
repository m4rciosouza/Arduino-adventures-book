// Define LED pins
const int redPin = 2;
const int yellowPin = 3;
const int greenPin = 4;

// Define timing parameters
const int redDuration = 5000;     // 5 seconds
const int yellowDuration = 2000;  // 2 seconds
const int greenDuration = 5000;   // 5 seconds

void setup() {
  // Set LED pins as OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Auto traffic light sequence
  turnOnGreen();
  delay(greenDuration);

  turnOnYellow();
  delay(yellowDuration);

  turnOnRed();
  delay(redDuration);
}

// Functions to control traffic light sequence
void turnOnRed() {
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
}

void turnOnYellow() {
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
}

void turnOnGreen() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
}