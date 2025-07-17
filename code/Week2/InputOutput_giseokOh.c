#include<stdio.h>

int main(void)
{
    float pie;
    printf("Input you think about pie\n");
    scanf("%f", &pie);
    printf("pie is...%0.2lf\n", pie);

    double score1;
    double score2;
    printf("Input score\n");
    scanf("%lf%lf", &score1, &score2);
    printf("your score is...\n%lf\t%lf", score1, score2);
    
    return 0;
}