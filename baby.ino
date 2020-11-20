#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

char auth[] = "";
char ssid[] = "";
char pass[] = "";
int pos = 0;
int mstatus = 0;
Servo servo;

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    servo.attach(15); //D8
}

void loop() {
    Blynk.run();
    Blynk.syncVirtual(V0);
}

BLYNK_WRITE(V0) {
    mstatus = param.asInt();
    if(mstatus == 1)
    {
        for(pos = 0; pos <= 180; pos += 1)
        {
            servo.write(pos);
            delay(10);
        }
        for(pos = 180; pos >= 0; pos -= 1)
        {
            servo.write(pos);
            delay(10);
        }
    }
}
