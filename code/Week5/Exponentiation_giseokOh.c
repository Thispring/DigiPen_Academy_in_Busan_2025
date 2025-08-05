/*
• Your program should prompt the user to enter a base(x) and an exponent(n).
• Implement a function to calculate 𝑥𝑛 using:
• Recursion
• Iteration(loop-based)
• ex) double PowerRecursive(double x, int n)
double PowerIterative(double x, int n)
• Display the result of exponentiation for both methods.
*/
#include <stdio.h>

double sum = 1; // 계산을 위한 전역변수 선언

double PowerRecursive(double base, int power);

int main(void)
{
    double base = 0; // 밑
    int power = 0;  // 지수

    double result = 0;  // 결과값

    printf("Input Base Number\n");
    scanf("%lf", &base);
    printf("Input Power Numer\n");
    scanf("%d", &power);

    result = PowerRecursive(base, power);
    printf("%lf\n", result);

    return 0;
}

double PowerRecursive(double base, int power)
{
    // power가 0보다 작거나 같다면
    if (power <= 0)
        return sum; // 함수를 중지하고 sum을 반환

    sum *= base; // 지역변수 sum에 base를 곱하여 대입
    printf("sum: %f\n", sum);

    return PowerRecursive(base, power - 1);
}
