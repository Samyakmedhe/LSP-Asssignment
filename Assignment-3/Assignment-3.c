#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

int copy_file(const char *src, const char *dest)
{
    int srcFd, destFd;
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    srcFd = open(src, O_RDONLY);
    if (srcFd == -1) return -1;

    struct stat st;
    if (stat(src, &st) == -1)
    {
        close(srcFd);
        return -1;
    }

    destFd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, st.st_mode);
    if (destFd == -1)
    {
        close(srcFd);
        return -1;
    }

    while ((bytesRead = read(srcFd, buffer, BUFFER_SIZE)) > 0)
    {
        write(destFd, buffer, bytesRead);
    }

    close(srcFd);
    close(destFd);
    return 0;
}

int main()
{
    char srcDir[100], destDir[100];
    DIR *dir;
    struct dirent *entry;
    struct stat st;
    char srcPath[300], destPath[300];
    int movedCount = 0;

    printf("Enter source directory: ");
    scanf("%s", srcDir);
    printf("Enter destination directory: ");
    scanf("%s", destDir);

    dir = opendir(srcDir);
    if (dir == NULL)
    {
        perror("Cannot open source directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(srcPath, sizeof(srcPath), "%s/%s", srcDir, entry->d_name);
        if (stat(srcPath, &st) == -1) continue;

        if (S_ISREG(st.st_mode))
        {
            snprintf(destPath, sizeof(destPath), "%s/%s", destDir, entry->d_name);

            if (rename(srcPath, destPath) != 0)
            {
                if (copy_file(srcPath, destPath) == 0)
                {
                    unlink(srcPath);
                }
                else
                {
                    printf("Failed to move: %s\n", entry->d_name);
                    continue;
                }
            }

            movedCount++;
        }
    }

    closedir(dir);

    printf("Total files moved: %d\n", movedCount);
    return 0;
}
