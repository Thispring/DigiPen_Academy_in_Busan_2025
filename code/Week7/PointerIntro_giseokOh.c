/*
• Declare three different types of variables (ex – int, float, char)
• Declare pointers for each of these variables
• Assign values to the variables using pointers
• Print the values using pointers
*/
#include <stdio.h>

int main(void)
{
    int ary[3];
    int *pa, *pb, *pc;

    for (int i = 0; i < 3; i++)
    {
        printf("Input Num ary[%d]\n", i);
        scanf("%d", &ary[i]);
    }

    pa = &ary[0];
    pb = &ary[1];
    pc = &ary[2];

    printf("pa: %d\n", *pa);
    printf("pb: %d\n", *pb);
    printf("pc: %d\n", *pc);

    // NOTE: zsh: segmentation fault -> 초기화 하지 않은 포인터 참조로 발생
    int *temp = pc;
    pc = pb;
    pb = pa;
    pa = temp;

    printf("pa: %d\n", *pa);
    printf("pb: %d\n", *pb);
    printf("pc: %d\n", *pc);

    return 0;
}