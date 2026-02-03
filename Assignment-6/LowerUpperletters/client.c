#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>


int main()
{
    char str[100];
    void *handle;

    int(*lower)(char*);
    int(*upper)(char*);
    int(*digits)(char*);
    
    printf("Enter string : ");
    fgets(str , sizeof(str ), stdin);

    handle = dlopen("./libStringCount.so",RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Unable to load the library\n");
        return 1;
    }

    lower  = dlsym(handle, "countlower");
    upper  = dlsym(handle, "countupper");
    digits = dlsym(handle, "countDigit");

    if(!lower || !upper || !digits)
    {
        printf("Unable to loading the function\n");
        dlclose(handle);
        return 1;
    }

    printf("Lowercase letters: %d\n", lower(str));
    printf("Uppercase letters: %d\n", upper(str));
    printf("Digits: %d\n", digits(str));

    dlclose(handle);
    return 0;
}