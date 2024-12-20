#include <Arduino.h>

#define ENCL 3
#define ENCR 2

#define step1 10  // steps to turn 90 degrees
#define step2 20  // steps to turn 180 degrees

volatile int ENCL_DATA;
volatile int ENCR_DATA;
volatile int stepsR = 0;
volatile int stepsL = 0;

void dclrEncoder ()
{
    pinMode(ENCL, INPUT);
    pinMode(ENCR, INPUT);
}

void readEcoder ()
{
    ENCL_DATA = digitalRead(ENCL);
    ENCR_DATA = digitalRead(ENCR);
    if (ENCL_DATA == 1)
    {
        stepsL++;
    }
    if (ENCR_DATA == 1)
    {
        stepsR++;
    }
}
