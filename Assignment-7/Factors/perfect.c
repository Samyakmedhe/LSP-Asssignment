#include "perfect.h"
#include "helper.h"

int IsPerfect(int iNo)
{
    int iSum =0 ;
    iSum = SumOfFactors(iNo);

    if(iSum == iNo)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}