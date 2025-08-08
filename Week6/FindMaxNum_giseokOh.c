/*
• Your program should
• prompt the user to enter 10 integers.
• Store the numbers in an array
• Find the maximum number from the array
• Display the maximum number to the user.
• Use a loop to input and process the numbers.
• Display the maximum number after all inputs have been entered.
*/
#include <stdio.h>

int main(void)
{
    int arr[10] = {0, };
    int maxNum = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Input arr[%d] num\n", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > maxNum)
        {
            maxNum = arr[i];
        }
    }
    printf("Maximum Num is %d\n", maxNum);

    return 0;
}