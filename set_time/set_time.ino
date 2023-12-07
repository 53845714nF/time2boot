#include "RTClib.h" // https://github.com/adafruit/RTClib
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);

  // start the connexion to the RTC

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1); // can't go further
  }
   rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));



  // or uncomment this line to decide what you want as a date/time for your RTC
  // format is year, month, day, hours, minutes, seconds
  // but you need to set that manually, take into account it takes a bit of time to compile, upload and run
  // so give yourself some padding in the seconds and check your wall clock and press reset on your arduino
  // when it's the right time. 

  // rtc.adjust(DateTime(2017, 7, 16, 16, 35, 20));

  Serial.println("RTC date is set");
}

void loop() {
  DateTime now = rtc.now();
  Serial.println(now.timestamp(DateTime::TIMESTAMP_TIME));
  delay(1000);
}