#include "Air_Quality_Sensor.h"
#include <LiquidCrystal.h>

AirQualitySensor sensor(A0);

LiquidCrystal lcd( 4, 6, 10, 11, 12, 13 );

void setup() {
  lcd.begin( 16, 2 );
  
  
  lcd.setCursor(0, 0);
  lcd.print("sensor to init");
  delay(20000);

  if (sensor.init()) {
        lcd.setCursor(0, 0);
  lcd.print("ready");
    } else {
        lcd.setCursor(0, 0);
  lcd.print("error");
    }
    lcd.clear();
}

void loop() {
  int quality = sensor.slope();
  int num=sensor.getValue();
  char string[5];
  lcd.setCursor(0, 0);
itoa(num,string,10);
    lcd.print("value:");
    lcd.setCursor(8, 0);
    lcd.print(num);
lcd.setCursor(0, 1);
    if (quality == AirQualitySensor::FORCE_SIGNAL) {
        lcd.print("Force signal active");
    } else if (quality == AirQualitySensor::HIGH_POLLUTION) {
        lcd.print("High pollution!");
    } else if (quality == AirQualitySensor::LOW_POLLUTION) {
        lcd.print("Low pollution!");
    } else if (quality == AirQualitySensor::FRESH_AIR) {
        lcd.print("Fresh air");
    }

    delay(3000);
    lcd.clear();
    
}
