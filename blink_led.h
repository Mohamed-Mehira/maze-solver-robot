#include <Arduino.h>

#define led 12

void dclrLed()
{
    pinMode(led, OUTPUT);
}

void blinkLed()
{
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);

}