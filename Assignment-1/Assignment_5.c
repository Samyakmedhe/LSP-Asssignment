#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char filename[50];
    int fd;
    int N;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter number of bytes to read: ");
    scanf("%d", &N);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        perror("File open failed");
        return 1;
    }

    char *buffer = (char *)malloc(N + 1);
    if (buffer == NULL)
    {
        printf("Memory allocation failed\n");
        close(fd);
        return 1;
    }

    int bytesRead = read(fd, buffer, N);
    if (bytesRead == -1)
    {
        perror("Read failed");
        free(buffer);
        close(fd);
        return 1;
    }

    buffer[bytesRead] = '\0'; 

    printf("Bytes read : %d :\n%s\n", bytesRead, buffer);

    free(buffer);
    close(fd);

    return 0;
}
