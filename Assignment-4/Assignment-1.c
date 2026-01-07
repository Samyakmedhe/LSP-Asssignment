#include<stdio.h>
#include<stdlib.h>


int main(int argc , char *argv[] )
{
    FILE *source , *destination;
    char ch ;

    if(argc != 3)
    {
        printf("Usage : copyfile source file destination file \n");
        return 1;
    }

    source = fopen(argv[1], "r");
    if(source == NULL)
    {
        printf("Error Source file not found or permission denied.\n");
        return 1;
    }

    destination = fopen(argv[2] , "w");

    if(destination == NULL)
    {
        printf("ERROR :Cannot create destination file\n");
        fclose(source);
        return 1;
    }

    while((ch = fgetc(source)) != EOF)
    {
        fputc(ch , destination);
    }
    
    printf("File copied successfully\n");

    fclose(source);
    fclose(destination);

    return 0;
}