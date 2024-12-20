// The robot is supposed to solve the maze using LSRB (wall following) algorithm, and once it reaches the end line
// it optimizes the path, turns around, and solves the maze again in reverse going through the shortest path.

#include <Arduino.h>
#include <motors.h>
#include <stdlib.h>


#define d1 500  // delay
#define minDistance 8

char path[50];
char path_op[50];
int i, j, counter = 0;


bool left = (leftDistance() > minDistance);
bool front_right = (frontDistance() > minDistance && rightDistance() > minDistance);
bool right = (rightDistance() > minDistance);
bool dead_end = (frontDistance() < minDistance);
bool intersection = (frontDistance() > minDistance || rightDistance() > minDistance || leftDistance() > minDistance);


void LSRB()  // the initial function to solve the maze 
{

    moveForward();

    if (left == true)
    {
        stop();
        delay(d1);
        path[counter] = 'L';
        counter++;
        turnL_P();
    }

    else if (front_right == true)
    {
        path[counter] = 'S';
        counter++;
    }

    else if (right == true)
    {
        stop();
        delay(d1);
        path[counter] = 'R';
        counter++;
        turnR_P();
    }

    else if (dead_end == true)
    {
        stop();
        delay(d1);
        path[counter] = 'B';
        counter++;
        turn_180();
    }
}

void LSRB_OP()  // function to construct the optimized path
{
    for (i = 0, j = 0; i < counter; j++)
    {
        if (path[i]=='L' && path[i+1]=='B' && path[i+2]=='R')
        {
            path_op[j] = 'B';
            i = i+3;
        }
        else if (path[i]=='L' && path[i+1]=='B' && path[i+2]=='S')
        {
            path_op[j] = 'R';
            i=i+3;
        }
        else if (path[i]=='R' && path[i+1]=='B' && path[i+2]=='L')
        {
            path_op[j] = 'B';
            i=i+3;
        }
        else if (path[i]=='S' && path[i+1]=='B' && path[i+2]=='L')
        {
            path_op[j] = 'R';
            i=i+3;
        }
        else if (path[i]=='L' && path[i+1]=='B' && path[i+2]=='L')
        {
            path_op[j] = 'S';
            i=i+3;
        }  
        else //in case none of the optimizations are possible
        {
            path_op[j] = path[i];
            i++;
        }
    }
}



void shortestPath()  // secondary function to traverse the maze through the optimal path after the initial iteration
{
    if(intersection == true)
    {
        if(path_op[j] == 'L')
        {
            stop();
            delay(d1);

            turnR_P();
            delay(d1);

            moveForward();
            j--;
        }
        else if (path_op[j] == 'S')
        {
            moveForward();
            j--;
        }
        else if (path_op[j] == 'R')
        {
            stop();
            delay(d1);

            turnL_P();
            delay(d1);
            
            moveForward();
            j--;
        }
    }
}




/*

void shortPath()  // while running
{
    if (path[counter] == '?' && path[counter-1] == '?' && path[counter-2] == '?')
        counter-=2;
        path[counter] = '?'
}

turnLeft();
path[counter] = 'L';

if (counter >= 2)
{
    shortPath();
}
counter++;

*/






