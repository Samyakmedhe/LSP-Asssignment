#include<stdio.h>
#include "perfect.h"


int main()
{

    int iNo = 0 ;
    int iRet = 0 ;

    printf("Enter number : ");
    scanf("%d",&iNo);

    iRet = IsPerfect(iNo);

    if(iRet == 1)
    {
        printf("%d is Perfect Number \n",iNo);

    }
    else
    {
        printf("%d is NOT Perfect Number \n",iNo);
    }
}