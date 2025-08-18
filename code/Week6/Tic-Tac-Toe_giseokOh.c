/*
목표: 배열과 조건문을 활용해 2인용 틱택토 게임을 구현한다.

3x3 char 배열 사용

플레이어 1은 X, 플레이어 2는 O

턴마다 좌표(x, y) 입력으로 말 놓기

승리 조건 확인 (가로, 세로, 대각선)

무승부 처리

게임 루프 포함 (반복문 사용)

최소 함수 1개 이상 사용할 것 (예: drawBoard(), checkWin() 등)

도전 과제(필수x): 플레이어 vs 플레이어가 아닌 플레이어 vs 컴퓨터 버전 만들어보기
*/
#include <stdio.h>
#include <stdlib.h>

int PlayerInput(int player); // int 매개변수로 플레이어 구별

int CheckGameResult(); // int를 return 하여, 승패 판별

int player = 1;       // 1, 2 값을 통해 플레이어 구분
char TicTacToe[3][3]; // 틱택토 배열 선언

int main(void)
{
    // 필요한 변수 선언
    int result = 0; // 결과 변수

    do
    {
        player = PlayerInput(player);
        if (player == 0)
            exit(0);
        result = CheckGameResult();
    } while (result != 0);
    // 승패가 판정되지 않으면 result를 0으로 설정

    return 0;
}

int PlayerInput(int player)
{
    // 좌표 입력 변수 선언
    int coordX;
    int coordY;
    printf("Player%d Input\n", player);
    scanf("%d%d", &coordX, &coordY);

    while (coordX > 2 || coordX < 0 || coordY > 2 || coordY < 0)
    {
        printf("Not a valid array number\n");
        printf("Player%d Input\n", player);
        scanf("%d%d", &coordX, &coordY);
    }

    while (TicTacToe[coordX][coordY] == 'O' || TicTacToe[coordX][coordY] == 'X')
    {
        printf("Array already entered\n");
        printf("Player%d Input\n", player);
        scanf("%d%d", &coordX, &coordY);
    }

    // switch 문으로 player 구별
    switch (player)
    {
    case 1:
        TicTacToe[coordX][coordY] = 'X';
        return 2; // 플레이어 변경
        break;
    case 2:
        TicTacToe[coordX][coordY] = 'O';
        return 1; // 플레이어 변경
        break;
    default:
        return 0; // 비정상 입력 예외 처리
        break;
    }
}

int CheckGameResult()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // 가로 기준 판별
            if (TicTacToe[i][j] == 'X')
            {
            }
            else if (TicTacToe[i][j] == 'O')
            {
            }
            else
            {
                // 입력 없는 자리에 * 임시 추가
                TicTacToe[i][j] = '*';
            }

            // 전체 좌표 출력
            printf("%c", TicTacToe[i][j]);
        }
        printf("\n");

        // 대각선 승리 조건
        if (TicTacToe[0][0] == 'X' && TicTacToe[1][1] == 'X' && TicTacToe[2][2] == 'X')
        {
            printf("player1 Win\n");
        }
        else if (TicTacToe[0][0] == 'O' && TicTacToe[1][1] == 'O' && TicTacToe[2][2] == 'O')
        {
            printf("player2 Win\n");
        }

    }

    return 1;
}