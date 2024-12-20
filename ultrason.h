#include <Arduino.h>

#define trigPinF 11
#define echoPinF A0

#define trigPinL A1
#define echoPinL 4

#define trigPinR 7
#define echoPinR 8


float duration;
float distance;


void dclrUltrason()
{
    pinMode(trigPinF, OUTPUT);
    pinMode(echoPinF, INPUT);
    pinMode(trigPinL, OUTPUT);
    pinMode(echoPinL, INPUT);
    pinMode(trigPinR, OUTPUT);
    pinMode(echoPinR, INPUT);
}

float frontDistance()
{
    digitalWrite(trigPinF, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinF, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinF, LOW);
    duration = pulseIn(echoPinF, HIGH);
    distance = duration * 0.034 / 2;
    return(distance);
}

float leftDistance()
{
    digitalWrite(trigPinL, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinL, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinL, LOW);
    duration = pulseIn(echoPinL, HIGH);
    distance = duration * 0.034 / 2;
    return(distance);
}

float rightDistance()
{
    digitalWrite(trigPinR, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPinR, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinR, LOW);
    duration = pulseIn(echoPinR, HIGH);
    distance = duration * 0.034 / 2;
    return(distance);
}

