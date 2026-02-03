#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *handle = NULL;
    int iRet = 0, iChoice = 0, iValue1 = 0, iValue2 = 0;
    int (*fp)(int, int) = NULL;

    handle = dlopen("./libserver.so", RTLD_LAZY);
    if(handle == NULL)
    {
        printf("ERROR : %s\n", dlerror());
        return -1;
    }

    printf("Library loaded successfully...\n");

    while(1)
    {
        printf("\n---------------- Dynamic Arithmetic ----------------\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("---------------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &iChoice);

        if(iChoice == 5)
        {
            printf("Exiting the program...\n");
            break;
        }

        if(iChoice < 1 || iChoice > 5)
        {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        printf("Enter first number : ");
        scanf("%d", &iValue1);
        printf("Enter second number : ");
        scanf("%d", &iValue2);

        switch(iChoice)
        {
            case 1:
                fp = (int (*)(int,int)) dlsym(handle, "Addition");
                break;
            case 2:
                fp = (int (*)(int,int)) dlsym(handle, "Subtraction");
                break;
            case 3:
                fp = (int (*)(int,int)) dlsym(handle, "Multiplication");
                break;
            case 4:
                fp = (int (*)(int,int)) dlsym(handle, "Division");
                break;
        }

        if(fp == NULL)
        {
            printf("ERROR : %s\n", dlerror());
            dlclose(handle);
            return -1;
        }

        iRet = fp(iValue1, iValue2);
        printf("Result is : %d\n", iRet);
    }

    dlclose(handle);
    return 0;
}
