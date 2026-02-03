#include <stdio.h>


int globalVar = 0;

void modifyValue(int val)
{
    globalVar += val;
}


void displayValue()
{
    printf("Global Variable Value: %d\n", globalVar);
}


void resetValue()
{
    globalVar = 0;
}
