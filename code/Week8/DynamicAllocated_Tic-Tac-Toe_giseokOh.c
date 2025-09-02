/*
목표: 동적 메모리 할당(malloc, free)을 이용하여 다양한 크기의 틱택토 게임을 만든다.

사용자에게 보드 크기 N 입력 받기 (예: 3 -> 3x3)

char** board 형태로 이중 포인터 동적 할당

모든 동작은 일반 버전과 동일하되, 메모리 동적 할당 기반

게임 종료 후 free로 메모리 해제

추가 과제 (옵션):

승리 조건을 N에 맞게 일반화
*/
#include <stdio.h>
#include <stdlib.h>

void MakeBorad(int size); // 틱택토 보드를 만드는 함수

void FreeBorad(int size);   // 동적할당 공간 반환 함수

int PlayerInput(int player); // int 매개변수로 플레이어 구별

int CheckGameResult(); // int를 return 하여, 승패 판별

int player = 1;       // 1, 2 값을 통해 플레이어 구분
int drawCount = 0;    // 무승부 판별 변수
int size = 0;
char **TicTacToe; // 틱택토 더블포인터 선언

int main(void)
{
    printf("틱택토 보드의 크기를 입력하세요:");
    scanf("%d", &size);

    // 동적할당으로 size크기 만큼 보드를 생성
    MakeBorad(size);
    
    // 필요한 변수 선언
    int result = 0; // 결과 변수

    do
    {
        if (drawCount >= 9)
        {
            printf("draw\n");
            break;
        }
        player = PlayerInput(player);
        if (player == 0)
            exit(0);
        result = CheckGameResult();
    } while (result == 0);
    // 승패가 판정되지 않으면 result를 0으로 설정
    // 승리한 player의 숫자를 반환
    
    FreeBorad(size);
    return 0;
}

void MakeBorad(int size)
{
    // main함수에서 입력받은 size와 포인터 TicTacToe를 활용해 동적할당
    // for문을 사용하여, 2차원 배열 생성
    TicTacToe = (char **)malloc(size * sizeof(char *));

    for (int i = 0; i < size; i++)
    {
        TicTacToe[i] = (char *)malloc(size * sizeof(char));
        for (int j = 0; j < size; j++)
        {
            TicTacToe[i][j] = ' ';
        }
    }

}

void FreeBorad(int size)
{
    for (int i = 0; i < size; i++)
    {
        free(TicTacToe[i]);
    }
    free(TicTacToe);
}

int PlayerInput(int player)
{
    // 좌표 입력 변수 선언
    int coordX;
    int coordY;
    printf("Player%d Input\n", player);
    scanf("%d%d", &coordX, &coordY);

    while (coordX > size || coordX < 0 || coordY > size || coordY < 0)
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
    // 틱택토 화면 출력
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (TicTacToe[i][j] != 'X' && TicTacToe[i][j] != 'O')
            {
                // 입력 없는 자리에 * 임시 추가
                TicTacToe[i][j] = '*';
            }

            // 전체 좌표 출력
            printf("%c", TicTacToe[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            // 대각선 승리 조건
            if (TicTacToe[0][0] == 'X' && TicTacToe[1][1] == 'X' && TicTacToe[2][2] == 'X')
            {
                printf("player1 Win\n");
                return 1;
            }
            else if (TicTacToe[0][0] == 'O' && TicTacToe[1][1] == 'O' && TicTacToe[2][2] == 'O')
            {
                printf("player2 Win\n");
                return 2;
            }
            if (TicTacToe[0][2] == 'X' && TicTacToe[1][1] == 'X' && TicTacToe[2][0] == 'X')
            {
                printf("player1 Win\n");
                return 1;
            }
            else if (TicTacToe[0][2] == 'O' && TicTacToe[1][1] == 'O' && TicTacToe[2][0] == 'O')
            {
                printf("player2 Win\n");
                return 2;
            }

            // 가로 승리 조건
            if (TicTacToe[j][0] == 'X' && TicTacToe[j][1] == 'X' && TicTacToe[j][2] == 'X')
            {
                printf("player1 Win\n");
                return 1;
            }
            else if (TicTacToe[j][0] == 'O' && TicTacToe[j][1] == 'O' && TicTacToe[j][2] == 'O')
            {
                printf("player2 Win\n");
                return 2;
            }

            // 세로 승리 조건
            if (TicTacToe[0][j] == 'X' && TicTacToe[1][j] == 'X' && TicTacToe[2][j] == 'X')
            {
                printf("player1 Win\n");
                return 1;
            }
            else if (TicTacToe[0][j] == 'O' && TicTacToe[1][j] == 'O' && TicTacToe[2][j] == 'O')
            {
                printf("player2 Win\n");
                return 2;
            }
        }
    }

    drawCount++;
    return 0;
}
