#include <Arduino.h>
#include <TM1637Display.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char* ssid = "";
const char* password = "";
const char* ntpServer = "pool.ntp.org";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, ntpServer);

// Define the CLK and DIO pins for TM1637
const int CLK_PIN = 12;  // Change this to the appropriate GPIO pin number
const int DIO_PIN = 13;  // Change this to the appropriate GPIO pin number

// Define the pin for the potentiometer
const int potentiometerPin = 33;

// Create an instance of TM1637Display
TM1637Display display(CLK_PIN, DIO_PIN);

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  timeClient.begin();
  timeClient.setTimeOffset(7200); // Set time offset (if required)
}

void loop() {
  timeClient.update();

  int potValue = analogRead(potentiometerPin);
  Serial.println(potValue);
  int brightness = map(potValue, 0, 4095, -1, 7);

  Serial.println(brightness);
  if(brightness >= 0){
    display.setBrightness(brightness);
      // Display "12:34" on the TM1637 display
    int hour = timeClient.getHours();
    int minute = timeClient.getMinutes();
    
    int displayValue = hour * 100 + minute;
    display.showNumberDecEx(displayValue, 0b01000000, true);
  } else{
    display.clear();
  }

  delay(200);
}