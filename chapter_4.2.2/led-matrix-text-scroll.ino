#include "WiFiS3.h"

char ssid[] = "YOUR_NETWORK_NAME";
char pass[] = "YOUR_NETWORK_PASSWORD";

// your network key index number
int keyIndex = 0;

int led = LED_BUILTIN;
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  // initialise serial and wait for port to open:
  Serial.begin(9600);

  Serial.println("Access Point Web Server");
  pinMode(led, OUTPUT);  // set the LED pin mode

  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // don't continue
    while (true)
      ;
  }

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // connect to WPA/WPA2 network
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  server.begin();

  // you're connected now, so print out the status
  printWiFiStatus();
}

void loop() {
  // listen for incoming clients
  WiFiClient client = server.available();

  if (client) {  // if you get a client
    // print a message out the serial port
    Serial.println("new client");
    // make a String to hold incoming data from the client
    String currentLine = "";
    // loop while the client's connected
    while (client.connected()) {
      // this is required for the Arduino Nano
      // RP2040 Connect - otherwise it will loop
      // so fast that SPI will never be served.
      delayMicroseconds(10);
      // if there's bytes to read from the client
      if (client.available()) {
        // read a byte, then
        char c = client.read();
        // print it out to the serial monitor
        Serial.write(c);
        // if the byte is a newline character
        if (c == '\n') {
          // if the current line is blank, you get
          // two newline characters in a row.
          // that's the end of the client HTTP request,
          // so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a
            // response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows
            // what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/H\">here</a> turn the LED on<br></p>");
            client.print("<p style=\"font-size:7vw;\">Click <a href=\"/L\">here</a> turn the LED off<br></p>");

            // the HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {  // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        // if you got anything else but a carriage return character
        else if (c != '\r') {
          // add it to the end of the currentLine
          currentLine += c;
        }

        // check to see if the client request
        // was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          // GET /H turns the LED on
          digitalWrite(led, HIGH);
        }
        if (currentLine.endsWith("GET /L")) {
          // GET /L turns the LED off
          digitalWrite(led, LOW);
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}

void printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}