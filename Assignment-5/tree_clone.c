#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void print_tree(const char *dirpath, int depth)
{
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char path[1024];

    dir = opendir(dirpath);
    if (dir == NULL)
        return;

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        sprintf(path, "%s/%s", dirpath, entry->d_name);

        if (lstat(path, &st) == -1)
            continue;

        for (int i = 0; i < depth; i++)
            printf("  ");

        if (S_ISDIR(st.st_mode))
        {
            printf("[D] %s\n", entry->d_name);
            print_tree(path, depth + 1);
        }
        else if (S_ISREG(st.st_mode))
        {
            printf("[F] %s\n", entry->d_name);
        }
        else if (S_ISLNK(st.st_mode))
        {
            printf("[L] %s\n", entry->d_name);
        }
        else
        {
            printf("[?] %s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    struct stat st;

    if (argc != 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    if (lstat(argv[1], &st) == -1)
    {
        perror("lstat");
        return 1;
    }

    if (S_ISDIR(st.st_mode))
    {
        printf("[D] %s\n", argv[1]);
        print_tree(argv[1], 1);
    }
    else if (S_ISREG(st.st_mode))
    {
        printf("[F] %s\n", argv[1]);
    }
    else if (S_ISLNK(st.st_mode))
    {
        printf("[L] %s\n", argv[1]);
    }

    return 0;
}
