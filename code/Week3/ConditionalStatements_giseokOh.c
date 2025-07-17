#include <stdio.h>

// Your program should get an integer input from the user.
// Use an if-else statement to check if it is positive or negative.
// Use switch statement to check if it is even or odd.
// You should print out the result to the console.

int main(void)
{
    int champion = 0;
    int weapon;

    printf("Input \"Champion Number:\"\n");
    printf("Don't input \"Champion Number\" the negative\n");

    while (champion <= 0)
    {
        scanf("%d", &champion);
        if (champion < 0)
        {
            printf("Don't input \"Champion Number\" the negative\n");
            continue;
        }
        else if (champion >= 10 && champion <= 99)
        {
            printf("Your Champion is \"Rare\"\n");
        }
        else if (champion == 100 || champion == 0)
        {
            printf("Your Champion is \"Legend\"\n");
            break;
        }
        else
        {
            printf("Your Champion is \"Normal\"\n");
        }
    }

    weapon = champion;

    switch (weapon % 2)
    {
    case 1:
        printf("Weapon Number is odd\n");
        break;
    case 0:
        printf("Weapon Number is even\n");
        break;
    default:
        printf("I don't know\n");
        break;
    }

    return 0;
}