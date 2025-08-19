/*
• Declare a 2D integer array of size 10 x 5 (int arr[5][10])
• Declare a pointer to the first element of the 2D array
• Use only pointer arithmetic to access and print all elements in row-major order
• Print the values in a formatted matrix style
*/
#include <stdio.h>

int main(void)
{
    int count = 1;
    int arr[5][10] = {0};
    int *pi;

    pi = &arr[0][0];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[i][j] = count++;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", *(*(arr + i) + j));
        }
        printf("\n");
    }

    return 0;
}