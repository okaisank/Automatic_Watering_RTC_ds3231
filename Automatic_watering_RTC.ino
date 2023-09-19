//https://github.com/jarzebski/Arduino-DS3231
#include <Wire.h>
#include <DS3231.h>

DS3231 clock;
RTCDateTime dt;

int motor = 12;
void setup()
{
  Serial.begin(9600);

  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();
pinMode(motor,OUTPUT);
  // Set sketch compiling time
//  clock.setDateTime(__DATE__, __TIME__);
}

void loop()
{
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  Serial.print("Raw data: ");
  Serial.print(dt.year);   Serial.print("-");
  Serial.print(dt.month);  Serial.print("-");
  Serial.print(dt.day);    Serial.print(" ");
  Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  Serial.print(dt.second); Serial.println("");

  delay(1000);

  if (dt.hour == 5 && dt.minute == 0 && dt.second == 0)// 05.00 
  {
    digitalWrite(motor,LOW);
    Serial.print("Morning watering");
    delay(30000);
  }
    if (dt.hour == 12 && dt.minute == 30 && dt.second == 0)//12.30 
  {
    digitalWrite(motor,LOW);
    Serial.print("Afternoon watering");
    delay(30000);
  }
      if (dt.hour == 17 && dt.minute == 30 && dt.second == 0)//17.30 
  {
    digitalWrite(motor,LOW);
    Serial.print("Evening watering");
    delay(30000);
  }
  else
  {
    digitalWrite(motor,HIGH);
  }
}
