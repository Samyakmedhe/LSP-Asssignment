#include<stdio.h>
#include<stdlib.h>


int main(int argc , char *argv[] )
{
    FILE *p ;
    long size;
    char ch;


    if(argc != 2)
    {
        printf("Reverse file name \n");
        return 1;
    }

    p = fopen(argv[1] ,"r");

    if(p == NULL)
    {
        printf("cannot open file\n");
        return 1;
    }

    fseek(p , 0 , SEEK_END);
    size = ftell(p);

    
    for(long i = size -1 ; i >= 0 ; i--)
    {
        fseek(p, i , SEEK_SET);
        ch = fgetc(p);
        putchar(ch);
    }

    fclose(p);
    
    return 0;
}