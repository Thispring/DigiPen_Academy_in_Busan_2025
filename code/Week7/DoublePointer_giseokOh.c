/*
• Declare an int type variable and a pointer to that variable
• Declare a double pointer that stores the address of the first pointer
• Assign values to the int type variable using both single and double pointers
• Print the int type variable’s value using the
• Variable
• single pointer
• double pointer
*/
#include <stdio.h>

int main(void)
{
    int num = 10;
    int *pa = &num;
    int **ppa = &pa;

    printf("%d\n", **ppa);

    return 0;
}