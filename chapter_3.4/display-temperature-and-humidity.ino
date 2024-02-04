// Define button pins
const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buttonPin4 = 5;

// Define piezo buzzer pin
const int buzzerPin = 9;

// Variables
int buttonState1, buttonState2, buttonState3, buttonState4;

void setup() {
  // Set button pins as INPUT with
  // pull-down resistors
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

  // Set piezo buzzer pin as OUTPUT
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read button states
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);

  // Check which button is pressed and
  // play the corresponding note
  if (buttonState1 == LOW) {
    playNote(262);  // Note: C4
  } else if (buttonState2 == LOW) {
    playNote(294);  // Note: D4
  } else if (buttonState3 == LOW) {
    playNote(330);  // Note: E4
  } else if (buttonState4 == LOW) {
    playNote(349);  // Note: F4
  } else {
    // Stop playing if no button is pressed
    noTone(buzzerPin);
  }
}

// Function to play a note on the piezo buzzer
void playNote(int frequency) {
  tone(buzzerPin, frequency);
  // Adjust the delay to control note duration
  delay(200);
  noTone(buzzerPin);
}