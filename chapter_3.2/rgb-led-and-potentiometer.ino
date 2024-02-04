// Define 7-segment display pins
const int segmentPins[] = { 2, 3, 4, 5, 6, 7, 8 };

// Define push button pins
const int increaseButtonPin = 9;
const int decreaseButtonPin = 10;

// Variables
int counter = 0;

void setup() {
  // Set 7-segment display pins as OUTPUT
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  // Set push button pins as INPUT
  pinMode(increaseButtonPin, INPUT_PULLUP);
  pinMode(decreaseButtonPin, INPUT_PULLUP);
}

void loop() {
  // Read button states
  int increaseButtonState = digitalRead(increaseButtonPin);
  int decreaseButtonState = digitalRead(decreaseButtonPin);

  // Increase counter when the increase button is pressed
  if (increaseButtonState == LOW && counter < 9) {
    counter++;
    delay(200);  // Debounce delay
  }

  // Decrease counter when the decrease button is pressed
  if (decreaseButtonState == LOW && counter > 0) {
    counter--;
    delay(200);  // Debounce delay
  }

  // Display the counter value on the 7-segment display
  displayNumber(counter);
}

// Function to display a number on the 7-segment display
void displayNumber(int number) {
  // Define the segment patterns for each digit
  int patterns[10][7] = {
    { 1, 1, 1, 1, 1, 1, 0 },  // 0
    { 0, 1, 1, 0, 0, 0, 0 },  // 1
    { 1, 1, 0, 1, 1, 0, 1 },  // 2
    { 1, 1, 1, 1, 0, 0, 1 },  // 3
    { 0, 1, 1, 0, 0, 1, 1 },  // 4
    { 1, 0, 1, 1, 0, 1, 1 },  // 5
    { 1, 0, 1, 1, 1, 1, 1 },  // 6
    { 1, 1, 1, 0, 0, 0, 0 },  // 7
    { 1, 1, 1, 1, 1, 1, 1 },  // 8
    { 1, 1, 1, 1, 0, 1, 1 }   // 9
  };

  // Display the specified number
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], patterns[number][i]);
  }
}