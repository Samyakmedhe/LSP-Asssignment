#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define BUFFER_SIZE 1024


int main(int argc , char *argv[] )
{
    int srcfd , destfd ;
    char buffer[BUFFER_SIZE];

    ssize_t bytes_read;

    off_t offset = 0 ;

    if(argc != 3)
    {
        printf("Copyfile source file destination file \n");
        return 1;
    }

    srcfd = open(argv[1] ,O_RDONLY);

    if(srcfd < 0)
    {
        perror("Error");
        return 1;
    }

    destfd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC , 0777);

    if(destfd < 0)
    {
        perror("Error ");
        close(srcfd);
        return 1;
    }

    while((bytes_read = pread(srcfd , buffer , BUFFER_SIZE , offset)) > 0 )
    {
        pwrite(destfd , buffer  , bytes_read , offset);
        offset += bytes_read;
    }

    printf("File copied sucessfully using pread() and pwrite()\n");
    close(srcfd);
    close(destfd);

    return 0;
}