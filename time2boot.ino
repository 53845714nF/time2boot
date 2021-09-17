// Date and time functions using a DS3231 RTC connected via I2C and Wire lib
#include "RTClib.h"

RTC_DS3231 rtc;
int optocoupler = 2;

void setup () {
  pinMode(optocoupler, OUTPUT);
  digitalWrite(optocoupler, LOW);
  
  Serial.begin(57600);

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, let's set the time!");
    // When time needs to be set on a new device, or after a power loss, the
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

}

void loop () {
  DateTime now = rtc.now();
  
  if (now.timestamp(DateTime::TIMESTAMP_TIME) == "00:00:00"){
    computerOn();
  }

  delay(1000);
}

void computerOn(){
  digitalWrite(optocoupler, HIGH);
  delay(200);
  digitalWrite(optocoupler, LOW);
}
