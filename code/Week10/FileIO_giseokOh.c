/*
• Store a predefined password into a file named password.txt
• Continuously prompt the user to enter a password using a while loop
• Read the stored password from password.txt and compare it with the user input
• If the entered password is correct, display a success message and terminate the program
• If the password is incorrect, prompt the user to try again
*/

// input과 file의 비밀번호가 맞는지 비교
#include <stdio.h>

typedef struct Info
{
    int password;
} INFO;

int main(void)
{
    INFO info;
    info.password = 1234;

    FILE *p_file = fopen("password.txt", "w");

    if (p_file == NULL)
    {

    }
    else
    {
        
    }

    fputs(p_file, info.password);

    int user = 0;

    do
    {
        printf("Input PassWord");
        scanf("%d", &user);
    } while (user != info.password);

    return 0;
}