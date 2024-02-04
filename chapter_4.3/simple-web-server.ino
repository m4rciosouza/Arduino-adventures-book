// include the RTC module
#include "RTC.h"

void setup() {
  // start the serial communication
  Serial.begin(9600);

  // start the RTC module
  RTC.begin();

  // define the initial date and time
  // to be set in the RTC module
  RTCTime startTime(
    01,
    Month::FEBRUARY,
    2024,
    16,
    37,
    00,
    DayOfWeek::THURSDAY,
    SaveLight::SAVING_TIME_ACTIVE);

  // set the time in the RTC module
  RTC.setTime(startTime);
}

void loop() {
  // declare a variable to hold the current time
  RTCTime currentTime;

  // get the current time from RTC
  RTC.getTime(currentTime);

  // print out date (DD/MM//YYYY)
  Serial.print(currentTime.getDayOfMonth());
  Serial.print("/");
  Serial.print(Month2int(currentTime.getMonth()));
  Serial.print("/");
  Serial.print(currentTime.getYear());
  Serial.print(" - ");

  // print time (HH/MM/SS)
  Serial.print(currentTime.getHour());
  Serial.print(":");
  Serial.print(currentTime.getMinutes());
  Serial.print(":");
  Serial.println(currentTime.getSeconds());

  // wait one second until get the next time
  delay(1000);
}