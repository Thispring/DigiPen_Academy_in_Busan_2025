/*
• Dynamically allocate memory for an array of 5 integers using malloc
• Assign values to the array elements using pointer arithmetic (e.g. *(arr+1))
• Print the values using both pointer and array notation
• Free the allocated memory at the end of the program
*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = (int *)malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("arr[%d]: %d\n", i, *(arr + i));
    }

    free(arr);

    return 0;
}