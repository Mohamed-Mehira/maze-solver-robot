#include "Arduino.h"

#define IR 12

int reading = analogRead(IR);

//condition when passing start or end line
bool line = (reading > 900);