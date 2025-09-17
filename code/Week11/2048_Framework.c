/*
2048

목표: 배열, 조건문, 반복문, 동적 메모리, 난수 생성 등 C의 주요 개념을 종합적으로 사용하여 간단한 2048 게임을 만든다.

* 4x4 보드 구현 (2차원 배열 또는 동적할당)
* 방향키 입력 시 숫자 이동 (w, a, s, d)
* 같은 숫자가 만나면 합쳐짐
* 매 이동 후 새로운 숫자(2 또는 4) 추가
* 게임 오버 조건 체크 (더 이상 움직일 수 없을 때)
* 점수 시스템 포함
* 최소 함수 5개 이상 분리 (예: moveLeft(), mergeTiles(), spawnNumber() 등)

추가 도전 과제:
* 최고 점수 저장
* 터미널에서 색상 사용 (ANSI escape code)
* undo 기능
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//*******handle input(no need to fix)********//
#ifdef _WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>

int _getch(void)
{
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#endif
//*******************************************//

#define SIZE 4

int board[SIZE][SIZE];
int backup_board[SIZE][SIZE];
int score = 0;
int backup_score = 0;
int high_score = 0;

// 초기에 2개의 랜덤 숫자와 이동 후 1개의 랜덤 숫자 생성
// 랜덤 숫자는 2 또는 4만 생성해야함
int numRand = 0;  // 랜덤으로 생성될 숫자
int XPosRand = 0; // 랜덤 생성 X축 위치
int YPosRand = 0; // 랜덤 생성 Y축 위치

void load_high_score(void)
{
    // TODO: read data from file and store it to the "high_score"
}

void save_high_score(void)
{
    // TODO: if "score" is higher than a "high_score" store it to the txt file(or binary)
}

void backup_board_state(void)
{
    // TODO: copy all data of "board[][]" into a "backup_board[][]"
    //       also copy "score" data into the "backup_score"
}

void undo_move(void)
{
    // TODO: copy all data of "backup_board[][]" into a "board[][]"
    //       also copy "backup_score" data into the "score"
}

//*******tile color settings(no need to fix)********//
void print_tile(int value)
{
    int color;
    switch (value)
    {
    case 0:
        color = 0;
        break; // Reset
    case 2:
        color = 37;
        break; // White
    case 4:
        color = 36;
        break; // Cyan
    case 8:
        color = 33;
        break; // Yellow
    case 16:
        color = 32;
        break; // Green
    case 32:
        color = 34;
        break; // Blue
    case 64:
        color = 35;
        break; // Magenta
    case 128:
        color = 31;
        break; // Red
    case 256:
        color = 90;
        break; // Bright Black (Gray)
    case 512:
        color = 91;
        break; // Bright Red
    case 1024:
        color = 92;
        break; // Bright Green
    case 2048:
        color = 93;
        break; // Bright Yellow
    default:
        color = 95;
        break; // Bright Magenta
    }

    if (value == 0)
        printf(" .\t");
    else
        printf("\033[1;%dm%d\t\033[0m", color, value); // Bold + color + value
}
//**************************************************//

//*******print out board(no need to fix)********//
void print_board(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
    printf("2048 GAME (WASD: move, U: undo, Q: quit)\n");
    printf("Score: %d\t High Score: %d\n\n", score, high_score);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            print_tile(board[i][j]);
        }
        printf("\n\n");
    }
}
//**********************************************//

void add_random_tile(void)
{
    // TODO: place a random tile in an 'empty spot' on the board.

    // 중복 위치를 기억하기 위한 변수
    int XdupeNum = 0;
    int YdupeNum = 0;

    // 중복 방지 선행 검사
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // 해당 조건에 만족하면 배열에 이미 숫자가 있다는 뜻
            if (board[i][j] != 0 && board[i][j] / 2 == 0)
            {
                // 중복 위치를 저장
                XdupeNum = j;
                YdupeNum = i;
                printf("중복위치입니다.\n");
                printf("XdupeNum: %d\n", XdupeNum);
                printf("YdupeNum: %d\n", YdupeNum);
            }
        }
    }

    do
    {
        numRand = ((rand() % 2) + 1) * 2; // 난수 생성 숫자를 2 또는 4로 제한
        // 랜덤한 범위 생성
        XPosRand = ((rand() % 4));
        YPosRand = ((rand() % 4));
        printf("numRand: %d\n", numRand);
        printf("XPosRand: %d\n", XPosRand);
        printf("YPosRand: %d\n", YPosRand);

        // 랜덤 생성 좌표가, 중복 위치값과 같다면
        if (XPosRand == XdupeNum && YPosRand == YdupeNum)
        {
            // 랜덤 숫자를 0으로 초기화 하고, 다시 반복문 진행
            XPosRand = 0;
            YPosRand = 0;
            continue;
        }
        else
        {
            // 중복이 없다면 중복 확인 변수를 0으로 유지
            XdupeNum = 0;
            YdupeNum = 0;
        }
        // 무작위 위치에 랜덤 숫자 생성
        board[YPosRand][XPosRand] = numRand;

    } while (XdupeNum != 0 && YdupeNum != 0);
}

void init_board(void)
{
    // TODO: initialize board and add two random tiles
    // 처음에만 랜덤 생성 2회 반복
    for (int i = 0; i < 2; i++)
    {
        printf("보드 초기화\n");
        add_random_tile();
    }
}

void rotate_board_clockwise(void)
{
    // TODO: rotate the board clockwise
}

int move_left(void)
{
    // TODO: Initialize 'moved' to 0.
    //       After processing, if the final board is different from the original board,
    //       set 'moved' to 1.
    int moved = 0;

    // TODO: For each row in the board:
    //   1. Create a temporary array (same size as the row) initialized with zeros.
    //   2. Copy all non-zero values from the row into the temporary array,
    //      shifted to the left, preserving their order.

    // 임시 계산 보드 선언 및 0으로 초기화
    int temp_board[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            temp_board[i][j] = 0;
        }
    }

    // 임시 계산 보드에, 기존 보드 값 입력
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            temp_board[i][j] = board[i][j];
        }
    }

    // TODO: Traverse the temporary array:
    //   - If two consecutive tiles have the same value and are non-zero:
    //       * Merge them into one tile (double the value of the first).
    //       * Add the merged value to the score.
    //       * Set the next tile to 0 (to prevent double merging).
    //       * Skip the next index to avoid chaining merges.

    // 이동 규칙: 한 행에 동일한 숫자가 4개가 있더라도, 합은 1번만 진행
    // ex) [2][2][2][2] -> [4][4][0][0]

    int nextTilePos = 0; // 정렬 시, 다음 타일의 위치

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // 우선 0이 아닌 값이 있는지 확인
            if (temp_board[i][j] != 0)
            {
                printf("0이 아닌 값 발견\n");
                // j가 3이라면, 행의 끝이므로 비교 중지
                if (j == 3)
                    break;

                // 0이 아닌 값이 있다면
                // 다음 tile과 비교 -> (값이 같은지, 0이 아닌지)
                for (int k = j + 1; k < SIZE; k++)
                {
                    if (temp_board[i][j] == temp_board[i][k])
                    {
                        printf("같은 값의 타일 입니다.\n");
                        // 다음 타일을 검사 했을 때, 같은 값이 있는 경우
                        // 같은 값끼리 곱한 후, 왼쪽으로 정렬
                        temp_board[i][nextTilePos] = temp_board[i][j] * temp_board[i][k];
                        printf("보드 변경: %d\n", temp_board[i][nextTilePos]);
                        // nextTilePos와 j가 같은경우
                        if (nextTilePos == j)
                        {
                            // [i][k] 위치만 0으로 변경
                            temp_board[i][k] = 0;
                            printf("[i][k]초기화\n");
                        }
                        else
                        {
                            temp_board[i][j] = 0;
                            temp_board[i][k] = 0;
                            printf("[i][j] + [i][k]초기화\n");
                        }

                        // 정렬이 끝나면 다음 위치 지정
                        nextTilePos++;
                        break;
                    }
                }

                // k for문으로 같은 값이 없다고 판별했기에, 왼쪽으로 정렬
                temp_board[i][nextTilePos] = temp_board[i][j];
                printf("nextTilePos: %d\n", nextTilePos);
                // nextTilePos와 j가 같은경우
                if (nextTilePos != j)
                {
                    temp_board[i][j] = 0;
                }
                nextTilePos++;
            }
            else
            {
                printf("0인값\n");
            }
        }
    }

    // 변경된 값 전달
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = temp_board[i][j];
        }
    }

    // TODO: After merging, compress the row again:
    //   - Move all non-zero values to the left side,
    //     filling remaining cells with zeros.

    // TODO: Copy the temporary array back into the actual board row.
    //   - If any value differs from the original board, set 'moved' to 1.

    // TODO: Return 'moved' to indicate whether at least one change occurred.

    // Examples (input row → output row):
    // [0,0,0,0]  → [0,0,0,0]
    // [2,0,0,0]  → [2,0,0,0]
    // [0,2,0,2]  → [4,0,0,0]
    // [2,2,0,0]  → [4,0,0,0]
    // [2,2,2,0]  → [4,2,0,0]
    // [2,2,2,2]  → [4,4,0,0]
    // [4,0,4,4]  → [8,4,0,0]
    // [4,4,8,8]  → [8,16,0,0]
    // [2,2,2,2,4,8] → [4,4,4,8,0,0]
}

int can_move(void)
{
    // TODO: return true(1) if at least one move is possible:
    // - Any empty cell exists
    // - Or any horizontal neighbors are equal
    // - Or any vertical neighbors are equal
    // Otherwise, return false(0).
    return 1;
}

int process_input(char input)
{
    int moved = 0;
    switch (input)
    {
    case 'a':
    case 'A':
        moved = move_left();
        break;
    case 'd':
    case 'D':
        rotate_board_clockwise();
        rotate_board_clockwise();
        moved = move_left();
        rotate_board_clockwise();
        rotate_board_clockwise();
        break;
    case 'w':
    case 'W':
        rotate_board_clockwise();
        rotate_board_clockwise();
        rotate_board_clockwise();
        moved = move_left();
        rotate_board_clockwise();
        break;
    case 's':
    case 'S':
        rotate_board_clockwise();
        moved = move_left();
        rotate_board_clockwise();
        rotate_board_clockwise();
        rotate_board_clockwise();
        break;
    }
    return moved;
}

int main(void)
{
    srand((unsigned int)time(NULL));
    load_high_score();
    init_board();

    while (1)
    {
        print_board();

        if (!can_move())
        {
            printf("Game Over!\n");
            save_high_score();
            break;
        }

        char input = _getch();
        if (input == 'q' || input == 'Q')
        {
            printf("Quitting...\n");
            save_high_score();
            break;
        }
        else if (input == 'u' || input == 'U')
        {
            undo_move();
            continue;
        }

        backup_board_state();
        if (process_input(input))
        {
            add_random_tile();
        }
    }

#ifdef _WIN32
    system("pause");
#endif
    return 0;
}