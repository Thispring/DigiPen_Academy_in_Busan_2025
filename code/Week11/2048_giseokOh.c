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

void load_high_score(void)
{
    // TODO: read data from file and store it to the "high_score"
    FILE *ps;
    ps = fopen("high_score.txt", "r");
    if (ps == NULL)
    {
        printf("fail open file\n");
        exit(1);
    }

    fscanf(ps, "%d", &high_score);
    fclose(ps);
}

void save_high_score(void)
{
    // TODO: if "score" is higher than a "high_score" store it to the txt file(or binary)

    // 저장할 때, 현재 score가 high_score 보다 높을 때만 저장하여 기록 갱신
    if (score >= high_score)
        high_score = score;

    FILE *ps;
    ps = fopen("high_score.txt", "w");
    if (ps == NULL)
    {
        printf("fail open file\n");
        exit(1);
        // 함수 리턴이 void 이므로 return 1 대신 exit 함수 사용
    }

    fprintf(ps, "%d", high_score);
    fclose(ps);
}

void backup_board_state(void)
{
    // TODO: copy all data of "board[][]" into a "backup_board[][]"
    //       also copy "score" data into the "backup_score"
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            backup_board[i][j] = board[i][j];
        }
    }
    backup_score = score;
}

void undo_move(void)
{
    // TODO: copy all data of "backup_board[][]" into a "board[][]"
    //       also copy "backup_score" data into the "score"
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = backup_board[i][j];
        }
    }
    score = backup_score;
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

    // 무작위 위치 값을 사용할 2개의 int 변수와, 2 또는 4의 값을 저장할 변수 선언
    int spawnNum = 0; // 턴마다 2또는 4를 저장할 변수
    int XPos = 0;     // 무작위로 지정할 2차원 배열의 열
    int YPos = 0;     // 무작위로 지정할 2차원 배열의 행

    // ((rand() % 2) + 1)으로 1또는 2를 무작위로 뽑은 뒤, 값에 *2를 하여, 2 또는 4 생성
    spawnNum = ((rand() % 2) + 1) * 2;

    do
    {
        // 위치값을 랜덤으로 생성
        XPos = rand() % SIZE;
        YPos = rand() % SIZE;

        // 만약 해당 위치에 0이 아닌 값이 있다면, 중복 위치 이므로, 재반복
        if (board[XPos][YPos] != 0)
        {
            continue;
        }
        else
        {
            board[XPos][YPos] = spawnNum;
            break;
        }
    } while (1);
}

void init_board(void)
{
    // TODO: initialize board and add two random tiles

    // 보드 초기화, add_random_tile 2회 반복
    for (int i = 0; i < 2; i++)
    {
        add_random_tile();
    }
}

int count = 0;
void rotate_board_clockwise(void)
{
    // TODO: rotate the board clockwise
    int rotateBoard[SIZE][SIZE] = {0}; 

    // 시계 방향 변화 관계식
    // (A, B) -> (B, 3 - A)
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] != 0)
            {
                rotateBoard[j][3 - i] = board[i][j];
                board[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = rotateBoard[i][j];
        }
    }
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

    int tempBoard[SIZE][SIZE] = {0};
    int nonZeroCount = 0; // 0이 아닌 값이 들어올 때 마다 더하여, 순서를 지정하는 변수

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // 0이 아닐때만 값을 복사
            if (board[i][j] != 0)
            {
                tempBoard[i][nonZeroCount] = board[i][j];
                nonZeroCount++; // 0이 아닌 값이 들어왔으므로 +1하여, 다음 순서로 이동
            }
        }
        nonZeroCount = 0; // 행이 바뀔 때 마다 0으로 초기화
    }

    // TODO: Traverse the temporary array:
    //   - If two consecutive tiles have the same value and are non-zero:
    //       * Merge them into one tile (double the value of the first).
    //       * Add the merged value to the score.
    //       * Set the next tile to 0 (to prevent double merging).
    //       * Skip the next index to avoid chaining merges.

    // 이동 규칙: 한 행에 동일한 숫자가 4개가 있더라도, 합은 1번만 진행
    // ex) [2][2][2][2] -> [4][4][0][0]
    // 점수 규칙: score 변수에 합쳐서 만든 숫자의 값 만큼 +
    // ex) [2][2][0][0] -> [4][0][0][0] 일때 4점 추가
    int next = 1; // 다음 타일과 비교를 위해, 위치값을 조절하는 변수

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // 숏 서킷 룰 활용, j가 3일 때 검사 생략
            if (j < 3 && tempBoard[i][j] != 0 && tempBoard[i][j] == tempBoard[i][j + next])
            {
                // tempBoard[i][j] 자리에 tempBoard 끼리 더한 값을 대입
                tempBoard[i][j] = tempBoard[i][j] * 2;
                // 점수 추가
                score += tempBoard[i][j];
                // 다음 타일을 0으로 만들어 중복 연산 방지
                tempBoard[i][j + next] = 0;
            }
        }
    }

    // TODO: After merging, compress the row again:
    //   - Move all non-zero values to the left side,
    //     filling remaining cells with zeros.

    // FIX: 배열에 0이 아닌 값을 왼쪽 정렬 후, 나머지 비어있는 배열은 0으로 초기화
    nonZeroCount = 0;
    
    int compBoard[SIZE][SIZE] = {0};    // tempBoard 값을 복사받아, 왼쪽 정렬 후, 원본 보드에 넣기 위한 배열

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            // 0이 아닐때만 값을 복사
            if (tempBoard[i][j] != 0)
            {
                compBoard[i][nonZeroCount] = tempBoard[i][j];
                nonZeroCount++; // 0이 아닌 값이 들어왔으므로 +1하여, 다음 순서로 이동
            }
        }
        nonZeroCount = 0; // 행이 바뀔 때 마다 0으로 초기화
    }

    // TODO: Copy the temporary array back into the actual board row.
    //   - If any value differs from the original board, set 'moved' to 1.

    // 실제 옮기기 전에 바뀐 내용이 있는지 선행 검사
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (compBoard[i][j] != board[i][j])
            {
                moved = 1;
                break;
            }
        }
    }

    // 값 중복을 막기 위해, 값을 넣기 전 원본 보드 0으로 초기화
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            board[i][j] = compBoard[i][j];
        }
    }

    // TODO: Return 'moved' to indicate whether at least one change occurred.
    return moved;

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
    int emptyCount = 0; // 0인 칸의 개수를 저장하기 위한 변수

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                emptyCount++;
            }
        }
    }

    if (emptyCount == 0)
        return 0;

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