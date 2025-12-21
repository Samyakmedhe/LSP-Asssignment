#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>


int main()
{
    char filename[30];
    char mode[5];

    int iRet = 0 ;
    printf("Enter file name : ");
    scanf("%s",filename);

    printf("Enter mode : (R / W / X) :  ");
    scanf("%s",mode);

    if(strcmp(mode, "R") == 0 )
    {
        iRet = access(filename , R_OK);
    }
    else if(strcmp(mode , "W") == 0 )
    {
        iRet = access(filename , W_OK);
    }
    else if(strcmp(mode , "X") == 0 )
    {
        iRet = access(filename , X_OK);
    }
    else
    {
        printf("Invalid mode\n");
        return 1;
    }

    if(iRet == 0 )
    {
        printf("Accessible\n");
    }
    else
    {
        if(errno == EACCES)
        {
            printf("Permission denied\n");
        }
        else if(errno == ENOENT)
        {
            printf("File does not Exist\n");
        }
        else
        {
            perror("Error : ");
        }
    }

    

    return 0;
}