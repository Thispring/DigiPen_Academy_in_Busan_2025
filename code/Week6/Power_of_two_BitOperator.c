// <비트 연산>을 사용하여 2의 제곱수를 판별하는 프로그램
/*
#include <stdio.h>

int main(void)
{
    unsigned int two[100]; // 2의 거듭제곱만 저장할 배열
    int j = 1;

    // << shift 연산으로 판별   
    // int 바이트 자릿수 고려하여, 반복은 30으로 제한
    for (int i = 0; i <= 30; i++)
    {
        two[i] = j << i;
    }

    for (int i = 0; i <= 30; i++)
    {
        printf("two[%d]: %d\n",i, two[i]);
    }
    
    return 0;
}
*/
#include <stdio.h>

// 2의 제곱수의 비트 특징으로, 비트 자리가 넘어가는 특징을 이용해
// -1을 한 숫자의 비트는 부호비트 제외 1로 이루어져 있기에, &연산 시(비트 끼리 비교 시 모두 1이어야지 1) 0이 나오는 특징을 이용
// 2의 제곱수가 아닌 숫자를 입력했을 때는, &연산이 가능하여 1이상이 무조건 나오므로 판별가능
int is2Power(unsigned int val)
{
    return (val&(val-1))==0;
}

int main(void)
{
    unsigned int input=0;

    scanf("%u",&input);
    if(is2Power(input) && input>0)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}