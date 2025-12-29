#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char dirname[100], filepath[300];
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    int deletedCount = 0;

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
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(filepath, sizeof(filepath), "%s/%s", dirname, entry->d_name);

        if (stat(filepath, &st) == -1)
            continue;

        if (S_ISREG(st.st_mode) && st.st_size == 0)
        {
            if (unlink(filepath) == 0)
            {
                printf("Deleted: %s\n", entry->d_name);
                deletedCount++;
            }
            else
            {
                printf("Failed to delete: %s\n", entry->d_name);
            }
        }
    }

    closedir(dir);

    printf("Total files deleted: %d\n", deletedCount);
    return 0;
}
