/*
• Use calloc to allocate memory for a string of 15 characters
• Copy a string value into that memory(e.g. “Hello World”)
• Print the string using the pointer
• Use realloc to resize the memory to hold a longer string
• Copy a longer string (e.g. “Hello Longer String!”) into the resized memory
• Print the new string and free the memory at the end
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* note = (char*)calloc(20, sizeof(char));
    
    strcpy(note, "HelloWorld");

    printf("note address: %p\n", (void *)note);
    printf("note size: %lu\n", strlen(note));
    printf("%s\n", note);

    note = realloc(note, 40 * sizeof(char));
    
    strcat(note, "HowlowWorld");

    printf("note address after realloc: %p\n", (void *)note);
    printf("note size after realloc: %lu\n", strlen(note));
    printf("%s\n", note);

    free(note);
    return 0;
}