#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 행렬 출력 함수
void print_matrix(int **mat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", mat[i][j]); // 요소 출력
        }
        printf("\n");
    }
}

// 행렬 덧셈 함수
void add_matrix(int **mat1, int **mat2, int **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j]; // 요소끼리 더함
        }
    }
}

// 행렬 뺄셈 함수
void subtract_matrix(int **mat1, int **mat2, int **result, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = mat1[i][j] - mat2[i][j]; // 요소끼리 뺌
        }
    }
}

// 행렬 전치 함수
void transpose_matrix(int **mat, int **result, int row, int col)
{
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            result[i][j] = mat[j][i]; // 행<->열 교환
        }
    }
}

// 행렬 곱셈 함수
void multiply_matrix(int **mat1, int **mat2, int **result, int row1, int col1, int row2, int col2)
{
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j]; // 행렬 곱하기
            }
        }
    }
}

// 메모리 해제 함수
void free_matrix(int **mat, int row)
{
    for (int i = 0; i < row; i++)
    {
        free(mat[i]); // 각 행에 할당된 메모리 해제
    }
    free(mat); // 행렬에 할당된 메모리 해제
}

int main()
{
    printf("[----- [hyunseung] [2023041001]] -----]\n");

    int row1, row2, col1, col2, **mat1, **mat2, **result;

    srand(time(NULL));

    printf("A: ");
    scanf("%d %d", &row1, &col1);
    printf("B: ");
    scanf("%d %d", &row2, &col2);

    // A 메모리 할당
    mat1 = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++)
    {
        mat1[i] = (int *)malloc(col1 * sizeof(int));
    }

    // B 메모리 할당
    mat2 = (int **)malloc(row2 * sizeof(int *));
    for (int i = 0; i < row2; i++)
    {
        mat2[i] = (int *)malloc(col2 * sizeof(int));
    }

    // 결과 행렬 메모리 할당
    result = (int **)malloc(row1 * sizeof(int *));
    for (int i = 0; i < row1; i++)
    {
        result[i] = (int *)malloc(col2 * sizeof(int));
    }

    // 행렬 A에 랜덤 값 할당
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            mat1[i][j] = rand() % 10;
        }
    }

    // 행렬 B에 랜덤 값 할당
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            mat2[i][j] = rand() % 10;
        }
    }

    // A 출력
    printf("\nA:\n");
    print_matrix(mat1, row1, col1);

    // B 출력
    printf("\nB:\n");
    print_matrix(mat2, row2, col2);

    // A + B 출력
    printf("\nA + B:\n");
    add_matrix(mat1, mat2, result, row1, col1);
    print_matrix(result, row1, col2);

    // A - B 출력
    printf("\nA - B:\n");
    subtract_matrix(mat1, mat2, result, row1, col1);
    print_matrix(result, row1, col2);

    // A 전치 출력
    printf("\nTranspose A:\n");
    transpose_matrix(mat1, result, row1, col1);
    print_matrix(result, col1, row1);

    // A * B 출력
    printf("\nA * B:\n");
    multiply_matrix(mat1, mat2, result, row1, col1, row2, col2);
    print_matrix(result, row1, col2);

    // 메모리 해제
    free_matrix(mat1, row1);
    free_matrix(mat2, row2);
    free_matrix(result, row1);

    return 0;
}