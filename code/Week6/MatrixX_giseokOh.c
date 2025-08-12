/*
• Your program should
• prompt the user to enter values for 2x3 and 3x2 matrices
• Store the numbers in two separate arrays.
• Multiply the two matrices
• Store the result in a third 2x2 array
• Display the resulting matrix to the user.
• output should have same form as a matrix
*/
#include <stdio.h>

int main(void)
{
    int xArray[2][3] = {0};
    int yArray[3][2] = {0};

    int resArray[2][2] = {0};

    // xArray 배열 값 입력
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Input xArray[%d][%d]\n", i, j);
            scanf("%d", &xArray[i][j]);
        }
    }

    // yArray 배열 값 입력
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Input yArray[%d][%d]\n", i, j);
            scanf("%d", &yArray[i][j]);
        }
    }

    // 두 배열의 곱을 resArray에 규칙에 맞게 대입
    for (int j = 0; j < 3; j++)
    {
        resArray[0][0] += (xArray[0][j] * yArray[j][0]);
        resArray[0][1] += (xArray[0][j] * yArray[j][1]);
        resArray[1][0] += (xArray[1][j] * yArray[j][0]);
        resArray[1][1] += (xArray[1][j] * yArray[j][1]);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%5d", resArray[i][j]);
        }
        printf("\n");
    }

    return 0;
}