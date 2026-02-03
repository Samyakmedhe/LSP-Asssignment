#include <stdio.h>
#include "mylib.h"

int main()
{
    printf("Initial value:\n");
    displayValue();

    printf("\nAdding 5:\n");
    modifyValue(5);
    displayValue();

    printf("\nAdding 15:\n");
    modifyValue(15);
    displayValue();

    printf("\nResetting value:\n");
    resetValue();
    displayValue();

    return 0;
}
