#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
    char filename[30];
    char mode[5];

    int fd = 0, flags = 0 ;
    printf("Enter file name : ");
    scanf("%s",filename);

    printf("Enter mode : R , W , RW , A ");
    scanf("%s",mode);

    if(strcmp(mode, "R") == 0 )
    {
        flags = O_RDONLY;
    }
    else if(strcmp(mode , "W") == 0 )
    {
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    }
    else if(strcmp(mode , "RW") == 0 )
    {
        flags = O_RDWR | O_CREAT;
    }
    else if(strcmp(mode, "A") == 0 )
    {
        flags = O_WRONLY | O_APPEND | O_CREAT;
    }
    else
    {
        printf("Invalid mode\n");
        return 1;
    }

    fd = open(filename , flags , 0777);
    
    if(fd == -1)
    {
        perror("open failed ");
        return -1;
    }

    printf("File opened sucessfully\n");
    printf("File Descriptor : %d\n",fd);

    close(fd);

    return 0;
}