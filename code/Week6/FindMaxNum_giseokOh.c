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
    int maxNum = 0; // 큰 수를 찾기 위한 비교용 변수

    for (int i = 0; i < 10; i++)
    {
        printf("Input arr[%d] num\n", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        // 만약 입력된 숫자가 maxNum보다 크다면
        if (arr[i] > maxNum)
        {
            // 입력된 숫자보다 큰 수 이므로, maxNum에 대입 후, for문 반복
            maxNum = arr[i];
        }
    }
    printf("Maximum Num is %d\n", maxNum);

    return 0;
}