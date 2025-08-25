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
    // rows와 cols의 순서에 따른 메모리 생성 순서 분석하기
    int rows = 3;
    int cols = 4;
    int **matrix = (int **)malloc(cols * sizeof(int*));

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int *)malloc(rows * sizeof(int));
    }

    fillMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < cols; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

void fillMatrix(int **matrix, int rows, int cols)
{
    int count = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = count;
            count++;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

/*
#include <stdio.h>
#include <stdlib.h>

void fillMatrix(int *matrix, int rows, int cols);
void printMatrix(int *matrix, int rows, int cols);

int main(void)
{
    int rows = 3;
    int cols = 3;
    int *matrix = (int *)malloc(rows * cols * sizeof(int*));

    fillMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    free(matrix);

    return 0;
}

void fillMatrix(int *matrix, int rows, int cols)
{
    int count = 1;
    for (int i = 0; i < rows * cols; i++)
    {
        matrix[i] = count;
        count++;
    }
}

void printMatrix(int *matrix, int rows, int cols)
{
    for (int i = 0; i < rows * cols; i++)
    {
        printf("%5d", matrix[i]);
    }
}
*/