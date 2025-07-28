// Your program should calculate the sum of only odds from 1 to 100
// You must use a for loop to perform the calculation
// Print each iterator value for every loop iteration and display the final sum on the console
#include <stdio.h>

int main(void)
{
    // 2500
    int i = 1;
    int result = 0;

    for (i = 1; i <= 100; i++)
    {
        // i%2 계산은 0과 1만을 출력하기에, i%2 == 0대신 i%2로 작성해도 가능
        // i&1를 하면 비트 연산 마지막이 1이면 홀수이기 때문에, 모든 비트가 1이면 1을 출력하는 AND(&)를 사용해서 홀수를 구별합니다.
        if (i&1)
        {
            result += i;
            printf("for[%d] result: %d\n", i, result);
        }
    }
    return 0;
}
