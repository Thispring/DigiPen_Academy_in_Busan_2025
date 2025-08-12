/*
목표: 함수 사용법과 반복문을 익히고, 난수 기반 숫자 맞추기 게임을 구현한다.

컴퓨터가 1~100 사이의 랜덤 숫자를 하나 고름

사용자가 숫자를 입력하면 더 높음/낮음을 출력

정답을 맞출 때까지 반복

시도 횟수를 정답 맞출 시 마지막에 출력

최소 함수 1개 이상 사용 (generateNumber(), playGame() 등)
*/
// TODO: (optional) 또한 1부터 100까지의 숫자를 입력했는지 판별하고, 범위 밖이라면 범위 내의 숫자를 입력하라는 메세지를 출력
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void generateNumber(int number);

int main(void)
{
    // 난수 생성을 위한 코드
    srand(time(NULL));
    int randNum = rand() % 100 + 1;

    // 숫자 맞추기 함수
    generateNumber(randNum);

    return 0;
}

/*
void generateNumber(int number)
{
    int userNum;    // 사용자가 입력할 번호
    int tryNum;     // 사용자의 시도 횟수
    printf("Input Number");
    scanf("%d", &userNum);

    while(userNum != number)
    {
        tryNum++;
        if (userNum < number)
        {
            printf("Up\n");
            scanf("%d", &userNum);
        }
        else
        {
            printf("Down\n");
            scanf("%d", &userNum);
        }
    }

    printf("Computer Num: %d, Your Try: %d\n", number, tryNum);
}
*/

void generateNumber(int number)
{
    int userNum; // 사용자가 입력할 번호
    int tryNum = 0;  // 사용자의 시도 횟수
    printf("Input Number");

    // do ~ while로 먼저 입력을 받고
    do
    {
        scanf("%d", &userNum);
        // 1부터 100까지의 범위가 아니라면
        // continue로 scanf 재입력 받기
        if (userNum <= 0 || userNum >= 101)
        {
            printf("Out of range Number, Try Again\n");
            continue;
        }

        tryNum++;
        printf("tryNum: %d\n", tryNum);
        if (userNum < number)
        {
            printf("Up\n");
            continue;
        }
        else
        {
            printf("Down\n");
            continue;
        }

    } while (userNum != number);

    printf("Computer Num: %d, Your Try: %d\n", number, tryNum);
}