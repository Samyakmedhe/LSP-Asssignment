#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>   
#include <unistd.h>

int main()
{
    char dirname[100], filename[100], filepath[PATH_MAX];
    DIR *dir;
    struct dirent *entry;
    int found = 0;

    printf("Enter directory name: ");
    scanf("%s", dirname);

    printf("Enter file name: ");
    scanf("%s", filename);

    dir = opendir(dirname);
    if (dir == NULL)
    {
        perror("Cannot open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, filename) == 0)
        {
            snprintf(filepath, sizeof(filepath), "%s/%s", dirname, filename);
            char absPath[PATH_MAX];
            if (realpath(filepath, absPath) != NULL)
            {
                printf("File found: %s\n", absPath);
            }
            else
            {
                printf("File found but cannot resolve absolute path\n");
            }
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("File not found in the directory.\n");
    }

    closedir(dir);
    return 0;
}
