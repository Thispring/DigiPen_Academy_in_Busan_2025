// <비트 연산>을 사용하여 2의 제곱수를 판별하는 프로그램
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