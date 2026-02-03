#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>


int main()
{

    void *handle;
    char *error;

    int (*Function[3])(int , int);
    
    char *FunctionName[] = {"Addition" , "Substraction" , "Multiplcation"};
    
    int A = 0 , B = 0 ;
    
    printf("Enter first Number : ");
    scanf("%d",&A);

    printf("Enter Second Number : ");
    scanf("%d",&B);

    handle = dlopen("./libserver.so", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load library : %s\n",dlerror());
        return 1;
    }

    dlerror();

    for (int i = 0; i < 3; i++)
    {
        Function[i] = (int (*)(int, int)) dlsym(handle, FunctionName[i]);

        if ((error = dlerror()) != NULL)
        {
            printf("Error loading %s: %s\n", FunctionName[i], error);
            dlclose(handle);
            return 1;
        }
    }

    printf("Function Address & Result:\n");

    for (int i = 0; i < 3; i++)
    {
        printf("%s -> Address: %p , Result: %d\n",
               FunctionName[i],
               (void *)Function[i],
               Function[i](A, B));
    }

    dlclose(handle);

    return 0;
}