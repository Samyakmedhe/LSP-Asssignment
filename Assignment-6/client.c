#include <stdio.h>
#include <dlfcn.h>

int main()
{
    void *handle;
    void (*fp)();
    char *error;

    handle = dlopen("libmylib.dylib", RTLD_LAZY);

    if(handle == NULL)
    {
        printf("Library load failed: %s\n", dlerror());
        return -1;
    }

    printf("Library loaded successfully.\n");

    dlerror();   // Clear old errors
    fp = (void (*)()) dlsym(handle, "HelloLibrary");

    error = dlerror();
    if(error != NULL)
    {
        printf("Symbol not found: %s\n", error);
        dlclose(handle);
        return -1;
    }

    fp();
    dlclose(handle);

    return 0;
}
