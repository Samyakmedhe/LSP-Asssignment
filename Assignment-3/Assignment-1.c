#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024


int main()
{
    int srcfd , destfd ;
    char src[100] , dest[100];
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    struct stat filestat;

    printf("Enter Source file name : ");
    scanf("%s",src);

    printf("Enter Destination file name : ");
    scanf("%s",dest);

    srcfd = open(src , O_RDONLY);
    if(srcfd == -1)
    {
        perror("Source file open error");
        return 1;
    }

    if(stat(src, &filestat) == -1)
    {
        perror("stat error ");
        close(srcfd);
        return 1;

    }
    destfd = open(dest , O_WRONLY | O_CREAT | O_TRUNC , filestat.st_mode);
    if(destfd == -1)
    {
        perror("Destination file open error");
        close(srcfd);
        return 1;
    }
    while((bytesRead = read(srcfd , buffer , BUFFER_SIZE)) >0)
    {
        write(destfd , buffer , bytesRead);
    }

    chmod(dest , filestat.st_mode);
    close(srcfd);
    close(destfd);

    printf("File copied successfully\n");
}