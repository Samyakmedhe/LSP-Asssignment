#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    char filename[50];
    struct stat sobj;
    int iRet = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    iRet = stat(filename, &sobj);
    if (iRet == -1)
    {
        perror("stat failed");
        return 1;
    }

    printf("\n----- File Information -----\n");

    
    printf("Total size in bytes : %lld\n", (long long)sobj.st_size);

    printf("Inode Number       : %lld\n", (long long)sobj.st_ino);

    printf("Hard Links         : %ld\n", (long)sobj.st_nlink);

    printf("Owner UID          : %d\n", sobj.st_uid);
    printf("Owner GID          : %d\n", sobj.st_gid);

    printf("Permissions        : ");
    printf((sobj.st_mode & S_IRUSR) ? "r" : "-");
    printf((sobj.st_mode & S_IWUSR) ? "w" : "-");
    printf((sobj.st_mode & S_IXUSR) ? "x" : "-");
    printf((sobj.st_mode & S_IRGRP) ? "r" : "-");
    printf((sobj.st_mode & S_IWGRP) ? "w" : "-");
    printf((sobj.st_mode & S_IXGRP) ? "x" : "-");
    printf((sobj.st_mode & S_IROTH) ? "r" : "-");
    printf((sobj.st_mode & S_IWOTH) ? "w" : "-");
    printf((sobj.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    printf("File Type          : ");
    if (S_ISREG(sobj.st_mode))
        printf("Regular File\n");
    else if (S_ISDIR(sobj.st_mode))
        printf("Directory\n");
    else if (S_ISCHR(sobj.st_mode))
        printf("Character Device\n");
    else if (S_ISBLK(sobj.st_mode))
        printf("Block Device\n");
    else if (S_ISFIFO(sobj.st_mode))
        printf("FIFO (Pipe)\n");
    else if (S_ISLNK(sobj.st_mode))
        printf("Symbolic Link\n");
    else if (S_ISSOCK(sobj.st_mode))
        printf("Socket\n");
    else
        printf("Unknown\n");

    printf("Last Access Time   : %s", ctime(&sobj.st_atime));
    printf("Last Modify Time   : %s", ctime(&sobj.st_mtime));

    return 0;
}
