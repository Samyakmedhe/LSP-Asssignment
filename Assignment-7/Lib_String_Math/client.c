#include <stdio.h>
#include "mystring.h"
#include "mymath.h"

int main()
{
    int mainChoice, strChoice, mathChoice;
    char str1[100], str2[100], dest[200];
    int n;
    char ch;
    char *ptr;
    int a, b;

    do
    {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. String Functions\n");
        printf("2. Math Functions\n");
        printf("3. Exit\n");
        printf("Enter choice : ");
        scanf("%d", &mainChoice);
        getchar();

        /* ---------- STRING MENU ---------- */
        if (mainChoice == 1)
        {
            do
            {
                printf("\n----- String Functions -----\n");
                printf("1. MyStrlen\n");
                printf("2. MyStrcpy\n");
                printf("3. MyStrncpy\n");
                printf("4. MyStrcmp\n");
                printf("5. MyStrncmp\n");
                printf("6. MyStrcat\n");
                printf("7. MyStrchr\n");
                printf("8. MyStrstr\n");
                printf("9. MyStrrev\n");
                printf("10. Back\n");
                printf("Enter choice : ");
                scanf("%d", &strChoice);
                getchar();

                switch (strChoice)
                {
                    case 1:
                        printf("Enter string : ");
                        fgets(str1, sizeof(str1), stdin);
                        printf("Length : %d\n", MyStrlen(str1));
                        break;

                    case 2:
                        printf("Enter source string : ");
                        fgets(str1, sizeof(str1), stdin);
                        MyStrcpy(dest, str1);
                        printf("Copied string : %s\n", dest);
                        break;

                    case 3:
                        printf("Enter source string : ");
                        fgets(str1, sizeof(str1), stdin);
                        printf("Enter n : ");
                        scanf("%d", &n);
                        getchar();
                        MyStrncpy(dest, str1, n);
                        printf("Result : %s\n", dest);
                        break;

                    case 4:
                        printf("Enter first string : ");
                        fgets(str1, sizeof(str1), stdin);
                        printf("Enter second string : ");
                        fgets(str2, sizeof(str2), stdin);
                        printf("Result : %d\n", MyStrcmp(str1, str2));
                        break;

                    case 5:
                        printf("Enter first string : ");
                        fgets(str1, sizeof(str1), stdin);
                        printf("Enter second string : ");
                        fgets(str2, sizeof(str2), stdin);
                        printf("Enter n : ");
                        scanf("%d", &n);
                        getchar();
                        printf("Result : %d\n", MyStrncmp(str1, str2, n));
                        break;

                    case 6:
                        printf("Enter destination string : ");
                        fgets(dest, sizeof(dest), stdin);
                        printf("Enter source string : ");
                        fgets(str1, sizeof(str1), stdin);
                        MyStrcat(dest, str1);
                        printf("Result : %s\n", dest);
                        break;

                    case 7:
                        printf("Enter string : ");
                        fgets(str1, sizeof(str1), stdin);
                        printf("Enter character : ");
                        scanf("%c", &ch);
                        getchar();
                        ptr = MyStrchr(str1, ch);
                        if (ptr != NULL)
                        {
                            printf("Character found at : %s\n", ptr);
                        }
                        else
                        {
                            printf("Character not found\n");
                        }
                        break;

                    case 8:
                        printf("Enter main string : ");
                        fgets(str1, sizeof(str1), stdin);
                        printf("Enter substring : ");
                        fgets(str2, sizeof(str2), stdin);
                        ptr = MyStrstr(str1, str2);
                        if (ptr != NULL)
                        {
                            printf("Substring found at : %s\n", ptr);
                        }
                        else
                        {
                            printf("Substring not found\n");
                        }
                        break;

                    case 9:
                        printf("Enter string : ");
                        fgets(str1, sizeof(str1), stdin);
                        MyStrrev(str1);
                        printf("Reversed string : %s\n", str1);
                        break;
                }

            } while (strChoice != 10);
        }

        /* ---------- MATH MENU ---------- */
        else if (mainChoice == 2)
        {
            do
            {
                printf("\n----- Math Functions -----\n");
                printf("1. MyAdd\n");
                printf("2. MySub\n");
                printf("3. MyMul\n");
                printf("4. MyDiv\n");
                printf("5. MyPow\n");
                printf("6. MySqrt\n");
                printf("7. MyAbs\n");
                printf("8. MyMax\n");
                printf("9. MyMin\n");
                printf("10. MyFactorial\n");
                printf("11. MyGCD\n");
                printf("12. MyLCM\n");
                printf("13. Back\n");
                printf("Enter choice : ");
                scanf("%d", &mathChoice);

                switch (mathChoice)
                {
                    case 1:
                        printf("Enter two numbers : ");
                        scanf("%d%d", &a, &b);
                        printf("Result : %d\n", MyAdd(a, b));
                        break;

                    case 2:
                        printf("Enter two numbers : ");
                        scanf("%d%d", &a, &b);
                        printf("Result : %d\n", MySub(a, b));
                        break;

                    case 3:
                        printf("Enter two numbers : ");
                        scanf("%d%d", &a, &b);
                        printf("Result : %d\n", MyMul(a, b));
                        break;

                    case 4:
                        printf("Enter two numbers : ");
                        scanf("%d%d", &a, &b);
                        printf("Result : %.2f\n", MyDiv(a, b));
                        break;

                    case 5:
                        printf("Enter base and exponent : ");
                        scanf("%d%d", &a, &b);
                        printf("Result : %d\n", MyPow(a, b));
                        break;

                    case 6:
                        printf("Enter number : ");
                        scanf("%d", &a);
                        printf("Square root : %.4f\n", MySqrt(a));
                        break;

                    case 7:
                        printf("Enter number : ");
                        scanf("%d", &a);
                        printf("Absolute : %d\n", MyAbs(a));
                        break;

                    case 8:
                        printf("Enter two numbers : ");
                        scanf("%d%d", &a, &b);
                        printf("Max : %d\n", MyMax(a, b));
                        break;

                    case 9:
                        printf("Enter two numbers : ");
                        scanf("%d%d", &a, &b);
                        printf("Min : %d\n", MyMin(a, b));
                        break;

                    case 10:
                        printf("Enter number : ");
                        scanf("%d", &a);
                        printf("Factorial : %d\n", MyFactorial(a));
                        break;

                    case 11:
                        printf("Enter two numbers : ");
                        scanf("%d%d", &a, &b);
                        printf("GCD : %d\n", MyGCD(a, b));
                        break;

                    case 12:
                        printf("Enter two numbers : ");
                        scanf("%d%d", &a, &b);
                        printf("LCM : %d\n", MyLCM(a, b));
                        break;
                }

            } while (mathChoice != 13);
        }

    } while (mainChoice != 3);

    return 0;
}
