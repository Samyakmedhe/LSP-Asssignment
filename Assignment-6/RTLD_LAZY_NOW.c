#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void * handle_lazy = NULL;
    void * handle_now = NULL;
    char  * error = NULL;
    int iRet = 0 ;

    int (*fp)(int , int );

    printf("------ Loading library with RTLD_LAZY------\n");

    handle_lazy = dlopen("./libsever.so", RTLD_LAZY);

    if(handle_lazy == NULL)
    {
        printf("RTLD_LAZY load failed : %s\n",dlerror());
        return -1;
    }
    else
    {
        printf("RTLD_LAZY sucessfuly loaded..\n");
    }

    printf("\n---- Loading library with RTLD_NOW ----\n");


    handle_now = dlopen("./libsever.so", RTLD_NOW);

    if(handle_now == NULL)
    {
        printf("RTLD_NOW load failed  : %s\n",dlerror());
        return -1;
    }
    else
    {
        printf("RTLD_NOW sucessfuly loaded..\n");
    }

    if(handle_lazy)
        dlclose(handle_lazy);

    if(handle_now)
        dlclose(handle_now);


    return 0;
}