#include<stdio.h>

int main(void)
{
    //todo: declare more than 10 types of variables;
    int i = 0;
    int j = 0;
    char chString = 'a';
    char chNum = 1;
    double score = 1.5;
    double time = 6.54;
    float pie = 3.14;
    int intSum = sizeof(i) + sizeof(j);
    char charSum = sizeof(chString) - sizeof(chNum);
    double doubleSum = sizeof(score) * sizeof(time);    

    return 0;
}