#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void * handle = NULL;
    char  * error = NULL;
    int iRet = 0 ;

    int (*fp)(int , int );

    handle = dlopen("./libsever.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("ERROR : %s\n",dlerror());
        return -1;
    }

    printf("libary gets sucessfuly loaded..\n");

    fp = (int (*) (int , int ))dlsym(handle , "Summmation");

    error = dlerror();

    if(error != NULL)
    {
        printf("Error : Failed to locate the function using dlsym()\n");
        printf("Reason : %s\n",error);
    }
    else
    {
        printf("Function found successfully.\n");
        printf("Result: %d\n", fp(10, 5));

    }

    dlclose(handle);


    return 0;
}