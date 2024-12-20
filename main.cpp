#include <IR.h>
#include <algorithm.h>

int A = 0;  // dummy variable


void setup() 
{
    Serial.begin(9600);
    dclrMotors();
    dclrUltrason();
    dclrEncoder();
    //  dclrCompass();

    attachInterrupt(digitalPinToInterrupt(ENCL), readEcoder, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCR), readEcoder, RISING);
}


void loop() 
{
    
    if (line == true && A == 0)  // start line detected
    {
        A = 1;
        delay(d1);
    }
    else if (line == true && A == 1)  // finish line detected
    {
        A = 2;  
        delay(d1);
        turn_180();
        stepsL = 0;
        stepsR = 0;
        delay(d1);
    }
    else if (line == true && A == 2)  // start line detected again after the second iteration (shortest path)
    {
        stop();
        A = 0;
    }
  

    if (A == 1)  // first iteration going through the maze to solve it initially
    {
        moveForward();

        selfCenter();

        LSRB();

        LSRB_OP();
    }
  
    if (A == 2)  // second iteration to optimally solve the maze
    {
        moveForward();

        selfCenter();

        shortestPath();  
    }

}