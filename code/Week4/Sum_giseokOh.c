// Your program should calculate the sum from 1 to 100
// You must use a while loop to sum the numbers from 1 to 50
// You must use a do-while loop to sum the numbers from 51 to 100
// Print each iterator value for every loop iteration and display the final sum on the console
#include <stdio.h>

int main(void)
{
    int i = 0;
    int result = 0;

    while (i < 50)
    {
        i++;
        result += i;
        printf("while[%d] result: %d\n", i, result);
        printf("i: %d\n", i);
    }

    do
    {
        i++;
        if (i == 101)
            break;
        
        result += i;

        printf("do ~ while[%d] result: %d\n", i, result);
        printf("i: %d\n", i);
    } while (1);

    printf("result: %d\n", result);
    return 0;
}