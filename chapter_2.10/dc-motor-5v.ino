// Define the digital pins for each segment
int segmentPins[] = { 2, 3, 4, 5, 6, 7, 8 };

void setup() {
  // Set each segment pin as an output
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  // Display numbers 0 to 9
  for (int i = 0; i <= 9; i++) {
    displayNumber(i);
    delay(1000);  // Display each number for 1 second
  }
}

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