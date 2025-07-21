#include <stdio.h>

// only use binary operation and make 1024
int main(void)
{
    int num1 = 1;

    num1 <<= 10;   

    printf("num1: %d\n", num1);

    int num2 = 0;

    num2 <<= 10;

    int num3 = ~num2;

    int num4 = num1 & num3;

    printf("num4: %d\n", num4);

    return 0;
}