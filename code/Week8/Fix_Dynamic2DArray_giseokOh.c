/*
• Define two variables(rows, columns) with MACRO(preprocessor)
• Dynamically allocate memory for a 2D integer matrix using int**
• Allocate memory for an array of int*(number of rows)
• For each row, allocate memory for columnsnumber of int
• Write a function void fillMatrix(int** matrix, int rows, int cols) that
• Fills the matrix such that element [i][j] = (i + 1) * (j + 1)
• Write a function void printMatrix(int** matrix, int rows, int cols) that
• Prints the matrix in table format
• Free all allocated memory at the end of the program
*/
// 1차원 배열로도 할당 해보기

#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);

int main(void)
{
    // rows와 cols의 순서에 따른 메모리 생성 순서 생각하기
    // rows(행): 가로 방향으로 줄을 세운 것
    // cols(열): 세로 방향으로 줄을 세운 것
    // [3][4] 2차원 배열 만들기
    int rows = 4;
    int cols = 3;

    // 가로의 길이를 먼저 정해줘야, 세로로 얼마나 쌓아야 하는지 알 수 있음
    int **matrix = (int **)malloc(rows * sizeof(int*));

    // 열의 개수 만큼 반복하여, rows로 만든 동적 공간을 세로로 쌓는다.
    for (int i = 0; i < cols; i++)
    {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // 2차원 배열에 값을 넣고 출력하는 함수 실행
    fillMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    // free 시에도 세로줄 부터 free
    for (int i = 0; i < cols; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void fillMatrix(int **matrix, int rows, int cols)
{
    // 안쪽 for문에 rows를, 바깥쪽 for문에 cols를 사용해야함
    int count = 1;
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            matrix[i][j] = count;
            count++;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols)
{
    // 안쪽 for문에 rows를, 바깥쪽 for문에 cols를 사용해야함
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}
