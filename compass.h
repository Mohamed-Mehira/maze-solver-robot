#include <Wire.h>
#include <QMC5883LCompass.h>

QMC5883LCompass compass;

void dclrCompass() 
{
  Serial.begin(9600);
  Wire.begin();
  compass.init();
}

int compassX()
{
  compass.read();
  return compass.getX();
}

int compassY()
{
  compass.read();
  return compass.getY();
}

int compassZ()
{
  compass.read();
  return compass.getZ();
}



