#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main()
{
    char filename[30];
    int fd = 0;
    printf("Enter file name : ");
    scanf("%s",filename);

    fd = open(filename, O_RDONLY);

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