#include "mystring.h"
#include <stdio.h>

int MyStrlen(const char *str)
{
    int iCount = 0;

    if (str == NULL)
    {
        return -1;
    }

    while (str[iCount] != '\0' && str[iCount] != '\n')
    {
        iCount++;
    }

    return iCount;
}

void MyStrcpy(char *dest, const char *src)
{
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void MyStrncpy(char *dest, const char *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void MyStrcat(char *dest, const char *src)
{
    while (*dest)
    {
        dest++;
    }

    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

int MyStrcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }

    return (*s1 - *s2);
}

int MyStrncmp(const char *s1, const char *s2, int n)
{
    int i = 0;

    while (i < n)
    {
        if (s1[i] != s2[i] || s1[i] == '\0')
        {
            return s1[i] - s2[i];
        }
        i++;
    }

    return 0;
}

void MyStrrev(char *str)
{
    int i = 0;
    int j = MyStrlen(str) - 1;
    char temp;

    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;

        i++;
        j--;
    }
}

char* MyStrchr(const char *str, char ch)
{
    while (*str)
    {
        if (*str == ch)
        {
            return (char *)str;
        }
        str++;
    }

    return NULL;
}

char* MyStrstr(const char *str, const char *substr)
{
    int i, j;

    for (i = 0; str[i] != '\0'; i++)
    {
        j = 0;
        while (substr[j] != '\0' && str[i + j] == substr[j])
        {
            j++;
        }

        if (substr[j] == '\0')
        {
            return (char *)&str[i];
        }
    }

    return NULL;
}
