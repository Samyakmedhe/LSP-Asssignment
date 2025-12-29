
#include<dirent.h>
#include<stdio.h>
#include<string.h>

#define BUFFER_SIZE 1024

int main()
{
    DIR *dir;

    struct dirent *entry;
    char dirname[100];

    printf("Enter directory name : ");
    scanf("%s", dirname);

    dir = opendir(dirname);
    if(dir == NULL) 
    {
        perror("Unable to open directory");
        return -1;
    }

    while((entry = readdir(dir)) != NULL)
    {
        if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
        {
            printf("%s\n",entry->d_name);
        }
    }
    
    closedir(dir);

    return 0;
}