/*
• Your program should
• Print a basic startup message(e.g., “program started”)
• Use #ifdef to conditionally display extra debug messages(try other things too)
• Always print a final message(e.g., “program ended”)
• Compile the program with and without the macro
• gcc –DMACRO Preprocessor_YourName.c
• gcc Preprocessor_YourName.c
*/
#include <stdio.h>

int main(void)
{
    printf("program started\n");

#ifdef DEBUG
    printf("debug msg\n");
#endif
    printf("program ended\n");

    return 0;
}