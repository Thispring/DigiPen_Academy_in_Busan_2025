#include <stdio.h>

/*
-목표: 조건문(if, else)과 연산자(+, -, *, /)를 이용해 간단한 계산기를 만든다.

-사용자가 입력한 두 수와 연산자(+, -, *, /)를 이용해 결과 출력

-사용자에게 숫자1, 연산자, 숫자2 입력 받기 (int, float, double, long 등 다양하게 사용해보고 무엇이 적합할지 생각해볼 것)

-+, -, *, / 연산 처리

-나눗셈은 0으로 나눌 경우 에러 메시지 출력

-잘못된 연산자가 들어오면 에러 메시지 출력
*/
int main(void)
{
    int num1;
    int num2;
    char operator;
    printf("Input first Num:\n");
    scanf("%d", &num1);
    printf("Input secound Num:\n");
    scanf("%d", &num2);

    printf("Input operator:\n");
    scanf("%c", &operator);


    return 0;
}