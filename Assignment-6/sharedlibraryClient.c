#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void * handle = NULL;

    int iRet = 0 ;

    int (*fp)(int , int );

    handle = dlopen("./libsever.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("ERROR : %s\n",dlerror());
        return -1;
    }

    printf("libary gets sucessfuly loaded..\n");

    fp = (int (*) (int , int ))dlsym(handle , "Addition");

    if(fp == NULL)
    {
        printf("ERROR : %s\n",dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(20 , 10 );

    printf("Addition is : %d\n",iRet);

    fp = (int (*) (int , int ))dlsym(handle , "Substraction");

    if(fp == NULL)
    {
        printf("ERROR : %s\n",dlerror());
        dlclose(handle);
        return -1;
    }

    iRet = fp(20 , 10 );

    printf("Substraction is : %d\n",iRet);
    
    dlclose(handle);


    return 0;
}