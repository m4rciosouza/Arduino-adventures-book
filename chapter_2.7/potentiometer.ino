#include <DHT.h>

// Pin for the DHT11 sensor
#define DHTPIN 2
// DHT sensor type
#define DHTTYPE DHT11  // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Read temperature and humidity data
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Print the data to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Add a delay to avoid overwhelming
  // the serial monitor
  delay(2000);
}