/*
Define a structure(struct Student)
to store the following information:
• Name (string)
• Age (integer)
• Grade (floating point)

Implement the following functions:
• void inputStudent(struct Student *s);
• this function should prompt the user to enter student
details
• Use a pointer to modify the structure data
• void printStudent(const struct Student *s);
• This function should print the student details

In the main() function:
• Declare a variable of type struct Student
• Call inputStudent(&student); to read student data
• Call printStudent(&student); to display the student data
*/
#include <stdio.h>
#include <string.h>

typedef struct Student
{
    char name[80];
    int age;
    float grade;
}STD;

void inputStudent(struct Student *s);

void printStudent(const struct Student *s);

int main(void)
{
    STD std;
    inputStudent(&std);
    printStudent(&std);

    return 0;
}

void inputStudent(struct Student *s)
{
    printf("Input Your name:");
    fgets(s->name, 80, stdin);
    
    printf("Input Your Age:");
    scanf("%d", &(s->age));

    printf("Input Your Grade:");
    scanf("%f", &(s->grade));
}

void printStudent(const struct Student *s)
{
    printf("Student Info\n");
    printf("Name:%s", s->name);
    printf("Age:%d\n", s->age);
    printf("Grade:%f\n", s->grade);
}