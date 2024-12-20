#include <Arduino.h>
#include <ultrason.h>
#include <math.h>
#include <compass.h>
#include <encoder.h> 

#define motorR1 5
#define motorR2 9

#define motorL1 6
#define motorL2 10


#define speed0 60
#define speed1 100
#define speed2 85

// #define speed_limit 70
// #define error_limit 1.2

int kp;
float error, error_sum;
float speedL, speedR;


void dclrMotors()
{
    pinMode(motorR1, OUTPUT);
    pinMode(motorR2, OUTPUT);
    pinMode(motorL1, OUTPUT);
    pinMode(motorL2, OUTPUT);
}


void moveForward()
{
    error = leftDistance() - rightDistance();
    if (error < 6)
    {
        kp = 10;
        error_sum = error * kp;
        speedR = constrain((error_sum + 255), 0, 255)
        speedL = constrain((255 - error_sum), 0, 255)

        Serial.print("SpeedR: ");
        Serial.println(speedR);
        Serial.print("  SpeedL: ");
        Serial.println(speedL);

        analogWrite(motorR1, speedR);
        analogWrite(motorL1, speedL);
    }
}


void moveBackward()
{
    analogWrite(motorR1, 0);
    analogWrite(motorR2, speed0);
    analogWrite(motorL1, 0);
    analogWrite(motorL2, speed0);
}


void stop()
{
    digitalWrite(motorR1, 0);
    digitalWrite(motorR2, 0);
    digitalWrite(motorL1, 0);
    digitalWrite(motorL2, 0);
}


void turnR_P()
{
    int stepsL_now = stepsL;
    int stepsR_now = stepsR;
    analogWrite(motorL1, speed1);
    analogWrite(motorL2, 0);
    analogWrite(motorR1, speed2);
    analogWrite(motorR2, 0);        
    while ((stepsL - stepsL_now < step1) || (stepsR - stepsR_now < step1))
    {
        delay(1);
    }
    
    stop();
}


void turnL_P()
{
    int stepsL_now = stepsL;
    int stepsR_now = stepsR;
    
    analogWrite(motorL1, speed2);
    analogWrite(motorL2, 0);
    analogWrite(motorR1, speed1);
    analogWrite(motorR2, 0);
    
    while ((stepsL - stepsL_now < step1) || (stepsR - stepsR_now < step1))
    {
        delay(1);
    }
    
    stop();
}


void turn_180()
{
    int stepsL_now = stepsL;
    int stepsR_now = stepsR;
    
    analogWrite(motorL1, 0);
    analogWrite(motorL2, speed1);
    analogWrite(motorR1, speed1);
    analogWrite(motorR2, 0);

    while ((stepsL - stepsL_now < step2) || (stepsR - stepsR_now < step2))
    {
        delay(1);
    }
    
    stop();
}



// void selfCenter()
// {
//     if (abs(rightDistance() - leftDistance()) >= error_limit)
//     {
//         while (rightDistance() > leftDistance())
//             analogWrite(motorR1, speed_limit);

//         while (leftDistance() > rightDistance())
//             analogWrite(motorL1, speed_limit);
//     }
// }



/*

// Using an IMU sensor instead of an optical encoder

void turnR_P()
{
    int tmpX = compassX();
    int tmpY = compassY();
    
    while (abs(tmpX - compassX()) < 90 && abs(tmpY - compassY()) < 90)
    {
    digitalWrite(motorR1, LOW);
    digitalWrite(motorR2, HIGH);
    digitalWrite(motorL1, HIGH);
    digitalWrite(motorL2, LOW);
    }
}

void turnL_P()
{
    int tmpX = compassX();
    int tmpY = compassY();
    
    while (abs(tmpX - compassX()) < 90 && abs(tmpY - compassY()) < 90)
    {
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
    }
}

void turn_180()
{
    int tmpX = compassX();
    int tmpY = compassY();
    
    while (abs(tmpX - compassX()) < 180 && abs(tmpY - compassY()) < 180)
    {
    digitalWrite(motorR1, HIGH);
    digitalWrite(motorR2, LOW);
    digitalWrite(motorL1, LOW);
    digitalWrite(motorL2, HIGH);
    }
}

*/
