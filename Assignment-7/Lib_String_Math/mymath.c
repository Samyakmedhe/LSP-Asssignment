#include "mymath.h"

int MyAdd(int a, int b)
{
    return a + b;
}

int MySub(int a, int b)
{
    return a - b;
}

int MyMul(int a, int b)
{
    return a * b;
}

double MyDiv(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }

    return (double)a / b;
}

int MyPow(int base, int exp)
{
    int result = 1;

    while (exp > 0)
    {
        result = result * base;
        exp--;
    }

    return result;
}

double MySqrt(double num)
{
    double x = num / 2.0;

    for (int i = 0; i < 10; i++)
    {
        x = (x + num / x) / 2.0;
    }

    return x;
}

int MyAbs(int x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

int MyMax(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int MyMin(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int MyFactorial(int n)
{
    int fact = 1;

    while (n > 0)
    {
        fact = fact * n;
        n--;
    }

    return fact;
}

int MyGCD(int a, int b)
{
    int temp;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int MyLCM(int a, int b)
{
    return (a * b) / MyGCD(a, b);
}
