#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    char dirname[100];
    char path[300];
    char largestFile[256] = "";
    long maxSize = 0;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dir = opendir(dirname);
    if (dir == NULL)
    {
        perror("Cannot open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        if (stat(path, &fileStat) == -1)
        {
            continue;
        }

        if (S_ISREG(fileStat.st_mode))
        {
            if (fileStat.st_size > maxSize)
            {
                maxSize = fileStat.st_size;
                strcpy(largestFile, entry->d_name);
            }
        }
    }

    closedir(dir);

    if (maxSize > 0)
    {
        printf("Largest file name: %s\n", largestFile);
        printf("Size (bytes): %ld\n", maxSize);
    }
    else
    {
        printf("No regular files found.\n");
    }

    return 0;
}
