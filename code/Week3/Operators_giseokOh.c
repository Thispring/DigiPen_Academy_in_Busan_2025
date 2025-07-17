#include <stdio.h>

// Declare 5 variables(can be more than 5)
// and do at least 10 operations.
// Print out all operation results.
int main(void)
{
    int i = 0;
    int j = 1;
    float pie = 3.14;
    long double king = 0;
    
    int a = -1;
    int sum = 0;
    int result = 0;

    sum = i + j;
    a -= sum;
    sum *= pie;

    result = (king != 0);
    a += result;
    sum = (sizeof(king) >= 32);
    a += sum;
    
    king = pie;
    a = result / ((int)king + (int)pie);

    result = (i > j) ? i : j; 
    
    printf("a is: %d\n", a);
    printf("sum is: %d\n", sum);
    printf("result is: %d\n", result);

    return 0;
}