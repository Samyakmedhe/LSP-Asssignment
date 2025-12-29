
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<String.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd = 0 ;
    char filename[100];
    char data[1024];
    ssize_t bytesWritten;



    printf("Enter File name : ");
    scanf("%s",filename);

    getchar();

    printf("Enter String to write in file : ");
    fgets(data, sizeof(data), stdin);

    fd = open(filename , O_WRONLY | O_APPEND| O_CREAT , 0777);

    if(fd == -1 )
    {
        perror("Error opeing file ");
        return -1;
    }

    bytesWritten = write(fd , data , strlen(data));

    if(bytesWritten == -1)
    {
        perror("Error wriiting to file");
        close(fd);
        return 1;
    }  

    close(fd);

    printf("Number of bytes written : %ld\n",bytesWritten);


    
    return 0;
}