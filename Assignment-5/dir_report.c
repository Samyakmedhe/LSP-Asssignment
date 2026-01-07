#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<limits.h>
#include<sys/stat.h>


long Totalfile = 0;
long Totaldirs = 0;
long TotalSize = 0 ;
long largestSize = 0;

char largestFile[PATH_MAX];

void DirectroyReport(const char *path)
{
    DIR *dp ;
    struct dirent *entry;
    struct stat statbuf ;
    char fullPath[PATH_MAX];

    dp = opendir(path);

    if(dp == NULL)
    {
        perror("Opendir");
        return ;

    }

    Totaldirs++;

    while((entry = readdir(dp)) != NULL)
    {

        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        snprintf(fullPath , sizeof(fullPath), "%s/%s", path , entry->d_name);

        if(lstat(fullPath , &statbuf) == -1)
        {
            continue;
        }

        if(S_ISREG(statbuf.st_mode))
        {
            Totalfile++;
            TotalSize += statbuf.st_size;

            if(statbuf.st_size > largestSize)
            {
                largestSize = statbuf.st_size;
                strcpy(largestFile , entry->d_name);
            }
        }
        else if(S_ISDIR(statbuf.st_mode))
        {
            DirectroyReport(fullPath);
        }

    }
    closedir(dp);
}



int main(int argc , char *argv[])
{
    if(argc != 2)
    {
        printf("%s Direct_path\n",argv[0]);
        return 1;
    }

    DirectroyReport(argv[1]);


    printf("Files : %ld\n",Totalfile);
    printf("Dirs : %ld\n",Totaldirs);
    printf("Total size : %lld Bytes\n",TotalSize);

    if(largestSize > 0 )
    {
        printf("Largest : %s (%lld bytes)\n" ,largestFile, largestSize);

    }
    else
    {
        printf("Largest : No regular file found\n");
    }


    return 0 ;
}