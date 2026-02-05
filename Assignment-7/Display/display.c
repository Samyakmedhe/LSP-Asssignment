#include<stdio.h>
#include "display.h"


void display(char *str)
{
    int iCount = 0;
    
    printf("String is : %s\n",str);

    while(str[iCount] != '\0')
    {
        if(str[iCount] != '\n')
        {
            iCount++;
        }
        else
        {
            break;
        }
        
    }
    printf("Total character : %d\n",iCount);
}