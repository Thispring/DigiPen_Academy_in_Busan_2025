#include <stdio.h>

int main(void)
{
    int arr_3D[2][2][3] = {{{2, 0, 25}, {1, 3, 5}, {2, 0, 24}, {9, 8, 7}}};

    int *i = **(arr_3D)+1;
    int *j = *(arr_3D)+1;
    printf("case1: %d\n", *i);
    printf("case2: %d\n", *j);
    
    return 0;
}