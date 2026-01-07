#include<stdio.h>
#include<stdlib.h>


int main(int argc , char *argv[] )
{
    FILE * out , *in;

    char ch ;
    int i ;

    if(argc < 3)
    {
        printf("merge output file , file1 , file2 ....\n");
        return 1;
    }

    out = fopen(argv[1], "w");
    if(out == NULL)
    {
        printf("Error : Cannot create..\n");
        return 1;
    }

    for(i = 2 ; i < argc; i++)
    {
        in = fopen(argv[i], "r");
        if(in == NULL)
        {
            printf("Error Cannot open input file %s\n",argv[i]);
            fclose(out);
            return 1;
        }
        while((ch = fgetc(in)) != EOF)
        {
            fputc(ch , out);
        }
        fclose(in);
    
    }

    fclose(out);
    printf("Files merged successfully\n");



    
    return 0;
}