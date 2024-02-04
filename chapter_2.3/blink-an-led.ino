// RGB LED Pins
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  // Set the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Set different colours
  setColor(255, 0, 0);  // Red
  delay(1000);

  setColor(0, 255, 0);  // Green
  delay(1000);

  setColor(0, 0, 255);  // Blue
  delay(1000);
}

void setColor(int red, int green, int blue) {
  // Set the colour of the RGB LED
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
