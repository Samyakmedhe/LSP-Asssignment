#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    char dirname[100];
    char path[300];

    printf("Enter directory name: ");
    scanf("%s", dirname);

    dir = opendir(dirname);
    if (dir == NULL) {
        perror("Cannot open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) 
    {
        if (strcmp(entry->d_name, ".") == 0 ||
            strcmp(entry->d_name, "..") == 0)
            continue;

        // Create full path
        snprintf(path, sizeof(path), "%s/%s", dirname, entry->d_name);

        // Get file information
        if (lstat(path, &fileStat) == -1) 
        {
            perror("lstat error");
            continue;
        }

        printf("%-20s : ", entry->d_name);

        if (S_ISREG(fileStat.st_mode))
            printf("Regular File");
        else if (S_ISDIR(fileStat.st_mode))
            printf("Directory");
        else if (S_ISLNK(fileStat.st_mode))
            printf("Symbolic Link");
        else if (S_ISFIFO(fileStat.st_mode))
            printf("FIFO");
        else if (S_ISSOCK(fileStat.st_mode))
            printf("Socket");
        else if (S_ISCHR(fileStat.st_mode))
            printf("Character Device");
        else if (S_ISBLK(fileStat.st_mode))
            printf("Block Device");
        else
            printf("Unknown");

        printf("\n");
    }

    closedir(dir);
    return 0;
}
