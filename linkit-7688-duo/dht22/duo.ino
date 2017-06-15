#include <Bridge.h>

#include "dht.h"

dht DHT;

#define DHT22_PIN A0

void setup()
{
    Serial.begin(115200);
    Bridge.begin();
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

void loop()
{

    Serial.print("DHT22: \t");

    switch (DHT.read22(DHT22_PIN))
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

    delay(1000);
}
