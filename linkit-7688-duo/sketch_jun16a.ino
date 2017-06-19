#include <math.h>
#include <Bridge.h>
#include "dht.h"


dht DHT;
#define DHT11_PIN A1
const int TouchPin=9;


void setup() {
  Serial.begin(9600);                //Start the Serial connection
  Bridge.begin();
  pinMode(TouchPin, INPUT);
}



void send_data()
{
    Serial.print(DHT.humidity, 1);
    Serial.print(",\t");
    Serial.print(DHT.temperature, 1);
    Serial.println();

    Bridge.put("h", String(DHT.humidity));
    Bridge.put("t", String(DHT.temperature));
}



void loop() {
  int sensorValue = analogRead(A0); 
  Serial.print("the analog read data is ");
  Serial.println(sensorValue);
  //Serial.println("the sensor resistance is ");
  //Serial.println(Rsensor,DEC);//show the light intensity on the serial monitor;

  int touchsensorValue = digitalRead(TouchPin);
  if(touchsensorValue==1)
  {
      Serial.println("touch say: dont touch me");
  }
  else
  {
      Serial.println("touch say: plz touch me");
  }

   Serial.print("DHT11: \t");

    switch (DHT.read11(DHT11_PIN))
    {
      case DHTLIB_OK:
          send_data();
          break;
      case DHTLIB_ERROR_CHECKSUM:
          Serial.println("Checksum error");
          break;
      case DHTLIB_ERROR_TIMEOUT:
          Serial.println("Time out error");
          break;
      case DHTLIB_ERROR_CONNECT:
          Serial.println("Connect error");
          break;
      case DHTLIB_ERROR_ACK_L:
          Serial.println("Ack Low error");
          break;
      case DHTLIB_ERROR_ACK_H:
          Serial.println("Ack High error");
          break;
      default:
          Serial.println("Unknown error");
          break;
    }


    Bridge.put("light", String(sensorValue));
    Bridge.put("touch", String(touchsensorValue));
    Serial.print("\n");
    delay(2000);
}
