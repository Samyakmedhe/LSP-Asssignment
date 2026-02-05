
#include<stdio.h>
#include "display.h"

int main()
{

    char str[100];
    
    printf("Enter String : ");
    fgets(str , sizeof(str), stdin);

    display(str);
    return 0;
}