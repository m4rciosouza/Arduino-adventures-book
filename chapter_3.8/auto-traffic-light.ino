// Define pin for the buzzer
const int buzzerPin = 2;

void setup() {
  // Set buzzer pin as OUTPUT
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Play "Happy Birthday"
  playHappyBirthday();
}

// Function to play "Happy Birthday"
void playHappyBirthday() {
  // Define the frequency values for each note
  int notes[] = {
    262, 262, 294, 262, 349, 330, 262, 262,
    294, 262, 392, 349, 262, 262, 523, 440,
    349, 330, 293, 293, 330, 293, 349, 392,
    392, 349, 330, 294, 294, 330, 294, 349,
    330, 262, 262, 294, 262, 349, 330, 262
  };

  // Define the duration for each note
  int duration = 300;

  // Iterate through the notes and play "Happy Birthday"
  for (int i = 0; i < 38; i++) {
    tone(buzzerPin, notes[i], duration);
    // Add a delay between notes for rhythm
    delay(500);
    // Turn off the buzzer after the note duration
    noTone(buzzerPin);
  }

  // Wait before playing again
  delay(2000);
}