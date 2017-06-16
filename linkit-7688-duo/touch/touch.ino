const int TouchPin=9;

#include <Bridge.h>


void setup() {
    Serial.begin(9600);
    pinMode(TouchPin, INPUT);
    Bridge.begin();
}

void loop() {
    int sensorValue = digitalRead(TouchPin);
    if(sensorValue==1)
    {
        Bridge.put("touch", "dont touch me");
    }
    else
    {
        Bridge.put("touch", "plz touch me");
    }
}
