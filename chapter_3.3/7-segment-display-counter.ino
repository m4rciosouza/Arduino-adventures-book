#include <DHT.h>
#include <LiquidCrystal.h>

// Pin for the DHT11 sensor
#define DHTPIN 7

// DHT sensor type
#define DHTTYPE DHT11  // DHT 11

DHT dht(DHTPIN, DHTTYPE);

// Initialise the library with the
// numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Initialize the DHT sensor
  dht.begin();

  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
}

void loop() {
  // Read temperature and humidity data
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Display temperature and humidity on LCD
  lcd.setCursor(8, 0);
  lcd.print(temperature, 1);
  lcd.setCursor(15, 0);
  lcd.print("C");

  lcd.setCursor(8, 1);
  lcd.print(humidity, 1);
  lcd.setCursor(15, 1);
  lcd.print("%");

  // Delay before next reading
  delay(2000);
}