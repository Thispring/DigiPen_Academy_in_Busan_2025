/*
• Your program should
• Prompt the user for input and store it in a char array.
• Declare and manipulate strings using <string.h> functions.
• Try multiple functions.
*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    char fruit[80];
    char food[80];

    printf("What kind of fruit do you want\n");  
    scanf("%s", fruit);

    printf("What kind of food do you want\n");
    scanf("%s", food);

    strcat(fruit, food);
    printf("Make %s!\n", fruit);

    return 0;
}