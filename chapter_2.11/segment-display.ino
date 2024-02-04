#include <LiquidCrystal.h>

// Initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // Print a message to the LCD
  lcd.print("Hello, Arduino!");
}

void loop() {
  // Set the cursor to the beginning of the second line
  lcd.setCursor(0, 1);

  // Print the number of seconds since reset
  lcd.print(millis() / 1000);

  delay(1000);  // Wait for a second
}