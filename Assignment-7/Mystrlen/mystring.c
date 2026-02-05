#include<stdio.h>
#include "mystring.h"


int MystrlenX(const char *str)
{
    int iCount = 0 ;

    if(str == NULL)
    {
        return -1;
    }
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
    return iCount;

}