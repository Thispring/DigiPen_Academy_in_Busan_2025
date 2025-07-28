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
    // 소수 입력을 위해 변수를 float로 설정하고, 길이를 제한
    float num1; 
    float num2;
    char operator;
    
    int checkNum = 0;   // 잘못된 연산자가 들어오는 것을 체크, 잘못된 연산자는 1, 나눗셈 시 0이 있으면 2로 표기

    float result;

    printf("Input First Num:\n");
    scanf("%f", &num1);

    printf("Input Secound Num:\n");
    scanf("%f", &num2);

    // 한글자 입력에 %s대신 %c사용
    printf("Input Operator:\n");
    scanf("%c", &operator);

    switch (operator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
    // 조건 검사할 필요 X -> 10/0 은 불가능하지만 0/10 가능하기에
        if (num1 == 0 || num2 ==0)
            checkNum = 2;  
        else
            result = num1 / num2;
        break;
    case '%':
        if (num1 == 0 || num2 ==0)
            checkNum = 2;
        else
            result = (int)num1 % (int)num2; // 나머지 계산은 정수로 바꿔야 가능하기에 int로 형변환
        break;
    default:
    // 해당 조건은 항상 참, 다른 조건 생각해보기
        if (operator != '+' || operator != '-' || operator != '*' || operator != '/' || operator != '%')
            checkNum = 1;
        break;
    }
   
    // 나눗셈에 0이 들어갔으면, 결과 출력을 하지 않음
    if (checkNum == 1)
        printf("비정상 연산자가 입력되었습니다.\n");
    else if (checkNum == 2)
        printf("0으로 나눌 수 없습니다.\n");
    else
        printf("Result is: %f\n", result);

    return 0;
}