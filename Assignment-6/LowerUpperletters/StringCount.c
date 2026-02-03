#include<stdio.h>


int countupper(char *str)
{
    int iCount = 0;

    while(*str)
    {
        if(*str >= 'A' && *str <= 'Z')
        {
            iCount++;
        }
        str++;
    }
    return iCount;
}


int countlower(char *str)
{
    int iCount = 0;

    while(*str)
    {
        if(*str >= 'a' && *str <= 'z')
        {
            iCount++;
        }
        str++;
    }
    return iCount;
}


int countDigit(char *str)
{
    int iCount = 0;

    while(*str)
    {
        if(*str >= '0' && *str <= '9')
        {
            iCount++;
        }
        str++;

    }
    return iCount;
}