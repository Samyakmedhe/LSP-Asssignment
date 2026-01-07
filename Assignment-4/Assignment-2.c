#include<stdio.h>
#include<stdlib.h>


int main(int argc , char *argv[] )
{
    FILE *source , *destination;
    char ch ;
    long offset;

    if(argc != 4)
    {
        printf("Usage : copyfile source file destination file , offset \n");
        return 1;
    }

    offset = atol(argv[3]);
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

    fseek(source , offset , SEEK_SET);
    while((ch = fgetc(source)) != EOF)
    {
        fputc(ch , destination);
    }
    
    printf("File copied successfully from offset : %lld \n",offset);

    fclose(source);
    fclose(destination);

    return 0;
}