/*
목표: 반복문, 조건문, 연산자, 난수 생성(rand) 등을 사용하여 가위바위보 게임을 만든다.

사용자로부터 가위(0), 바위(1), 보(2) 중 하나 입력 받기

컴퓨터는 rand()를 이용하여 무작위 선택

결과를 비교하여 승, 패, 무승부 판별

srand(time(NULL))를 사용하여 매 실행 시 난수값 달라지게 만들기
*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void)
{
    int user = 0;   // 플레이어 입력값
    int result = 0; // 결과값

    srand(time(NULL));

    // 입력값을 반복하여 받기 위해 do~while 사용
    do
    {
        printf("Scissors(0) / Rock(1) / Paper(2)\n");
        scanf("%d", &user);

        int randNum = rand() % 3; //  rand함수 리턴값이 어떤 숫자가 나와도 나머지 값은 0, 1 or 2가 나온다

        result = user - randNum;    // 입력값과 난수 뺄샘을 통해 승패 구별
        // 1 or -2이면 플레이어 승리
        // 2 or -1이면 플레이어 패배
        // 0이면 무승부

        if (user != 0 && user != 1 && user != 2) // 0, 1, 2 외에 다른 숫자를 입력할 경우
        {
            printf("User:%d\n", user);
            printf("Wrong Number.\n");
            result = 3; // result에 3을 대입하여, while 반복
            continue;
        }

        switch (result)
        {
        case 0:
            printf("Draw! User:%d Computer:%d\n", user, randNum);
            continue;
        case 1:
            printf("Win! User:%d Computer:%d\n", user, randNum);
            break;
        case -2:
            printf("Win! User:%d Computer:%d\n", user, randNum);
            break;
        case 2:
            printf("Lose! User:%d Computer:%d\n", user, randNum);
            break;
        case -1:
            printf("Lose! User:%d Computer:%d\n", user, randNum);
            break;
        }
        // 컴퓨터가 낸 것 vs 유저가 낸 것 비교
    } while (result == 0 || result == 3);   // 비기거나, 잘못된 숫자 입력 시 반복

    return 0;
}
