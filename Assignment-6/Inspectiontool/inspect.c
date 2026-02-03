#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    void *handle;
    void *symbol;
    char *error;

    if (argc != 3)
    {
        printf("Usage: %s <shared_library_path> <symbol_name>\n", argv[0]);
        return 1;
    }

    handle = dlopen(argv[1], RTLD_LAZY);
    if (!handle)
    {
        printf("Library loading failed: %s\n", dlerror());
        return 1;
    }

    dlerror();

    symbol = dlsym(handle, argv[2]);
    if ((error = dlerror()) != NULL)
    {
        printf("Symbol '%s' not found: %s\n", argv[2], error);
        dlclose(handle);
        return 1;
    }

    printf("Symbol '%s' found at address: %p\n", argv[2], symbol);

    dlclose(handle);
    return 0;
}
