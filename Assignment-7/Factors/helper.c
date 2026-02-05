#include "helper.h"

int SumOfFactors(int iNo)
{
    int i = 0 ;
    int iSum =0 ;

    for(i = 1 ; i <= iNo/2 ;i++)
    {
        if(iNo % i == 0 )
        {
            iSum = iSum + i;
        }
    }
    return iSum;
}
