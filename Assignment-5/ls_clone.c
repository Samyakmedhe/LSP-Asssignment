#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

void print_permissions(mode_t mode)
{
    char perm[10];

    perm[0] = (mode & S_IRUSR) ? 'r' : '-';
    perm[1] = (mode & S_IWUSR) ? 'w' : '-';
    perm[2] = (mode & S_IXUSR) ? 'x' : '-';
    perm[3] = (mode & S_IRGRP) ? 'r' : '-';
    perm[4] = (mode & S_IWGRP) ? 'w' : '-';
    perm[5] = (mode & S_IXGRP) ? 'x' : '-';
    perm[6] = (mode & S_IROTH) ? 'r' : '-';
    perm[7] = (mode & S_IWOTH) ? 'w' : '-';
    perm[8] = (mode & S_IXOTH) ? 'x' : '-';
    perm[9] = '\0';

    printf("%s", perm);
}

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    char path[1024];

    if (argc != 2)
    {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    dir = opendir(argv[1]);
    if (dir == NULL)
    {
        perror("Cannot open directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        sprintf(path, "%s/%s", argv[1], entry->d_name);

        if (stat(path, &fileStat) == -1)
            continue;

        printf("Name: %s\n", entry->d_name);

        printf("Type: ");



        if (S_ISREG(fileStat.st_mode))
            printf("File\n");
        else if (S_ISDIR(fileStat.st_mode))
            printf("Directory\n");
        else if (S_ISLNK(fileStat.st_mode))
            printf("Link\n");
        else
            printf("Other\n");

        printf("Size: %ld bytes\n", fileStat.st_size);

        printf("Permissions: ");
        print_permissions(fileStat.st_mode);
        printf("\n");

        printf("Last Modified: %s", ctime(&fileStat.st_mtime));
        printf("---------------------------\n");
    }

    closedir(dir);
    return 0;
}
