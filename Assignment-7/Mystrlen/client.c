#include<stdio.h>
#include "mystring.h"

int main()
{

    char str[100];
    int iRet = 0 ;

    printf("Enter String : ");
    fgets(str, sizeof(str), stdin);

    iRet = MystrlenX(str);

    if(iRet == -1)
    {
        printf("NULL string passed\n");
    }
    else
    {
        printf("length of String is %d\n",iRet);
    }
    return 0;
}