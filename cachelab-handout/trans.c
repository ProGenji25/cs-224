/* Thomas Liddle
 * tliddle1
 * Jordan Golden
 * golde3
 * Trevor Brown
 * trevorsb
 * Christopher Dutson
 * dutsonc
 */

/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */

void matrix_32x32(int M, int N, int A[N][M], int B[N][M])
{
    int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8;
    for (i = 0; i < N; i += 8)//choose row section to be copied (8 x 8)
    {
       for (j = 0; j < M; j += 8)//choose column section to be copied (8 x 8)
       {
           for (k = i; k < i + 8; k++)//set row number in A
           {
               for (l = j; l < j + 8; l += 8)//set column number in A
               {
                   t1 = A[k][l];//save values in A to be put into B
                   t2 = A[k][l + 1];
                   t3 = A[k][l + 2];
                   t4 = A[k][l + 3];
                   t5 = A[k][l + 4];
                   t6 = A[k][l + 5];
                   t7 = A[k][l + 6];
                   t8 = A[k][l + 7];
                   B[l][k] = t1;//take those values from A (in the variables) and put in transpose matrix B
                   B[l + 1][k] = t2;
                   B[l + 2][k] = t3;
                   B[l + 3][k] = t4;
                   B[l + 4][k] = t5;
                   B[l + 5][k] = t6;
                   B[l + 6][k] = t7;
                   B[l + 7][k] = t8;
                }
            }
        }
    }
}

void matrix_64x64(int M, int N, int A[N][M], int B[N][M])
{
    int i, j, k, l, t1, t2, t3, t4, t5, t6, t7, t8;
    for (i = 0; i < N; i += 8) //selection of row number incrementing by 8 (doing one 8x8 at a time)
    {
        for (j = 0; j < M; j += 8) //setting column nuber in A
        {
            for (k = i; k < i + 4; k++) //setting row number in A
            {
                t1 = A[k][j]; // takes first row in A and assigns to variables
                t2 = A[k][j + 1];
                t3 = A[k][j + 2];
                t4 = A[k][j + 3];
                t5 = A[k][j + 4];
                t6 = A[k][j + 5];
                t7 = A[k][j + 6];
                t8 = A[k][j + 7];

                B[j][k] = t1; //puts values in variables into B (some won't be in the correct spot at first to minimize cache thrashing)
                B[j + 1][k] = t2;
                B[j + 2][k] = t3;
                B[j + 3][k] = t4;
                B[j][k + 4] = t5;
                B[j + 1][k + 4] = t6;
                B[j + 2][k + 4] = t7;
                B[j + 3][k + 4] = t8;
            }
            for (l = j + 4; l < j + 8; l++) //since some values in B are not in the right spot, this puts everything where it should be
            {
                t5 = A[i + 4][l - 4];//put bottom left section of A into variables 5-8
                t6 = A[i + 5][l - 4];
                t7 = A[i + 6][l - 4];
                t8 = A[i + 7][l - 4];

                t1 = B[l - 4][i + 4];//put top right section of B into variables 1-4
                t2 = B[l - 4][i + 5];
                t3 = B[l - 4][i + 6];
                t4 = B[l - 4][i + 7];

                B[l - 4][i + 4] = t5;//put values from bottom left of A into top right section of 8x8 in B
                B[l - 4][i + 5] = t6;
                B[l - 4][i + 6] = t7;
                B[l - 4][i + 7] = t8;

                B[l][i] = t1; //put what was in top right of B (but wasn't correct at first) into bottom left of B where it belongs
                B[l][i + 1] = t2;
                B[l][i + 2] = t3;
                B[l][i + 3] = t4;

                B[l][i + 4] = A[i + 4][l];//copy bottom right of A into bottom right of B
                B[l][i + 5] = A[i + 5][l];
                B[l][i + 6] = A[i + 6][l];
                B[l][i + 7] = A[i + 7][l];
            }
        }
    }
}


char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    if (M == 32 && N == 32)//if matrix is 32x32
    {
        matrix_32x32(M, N, A, B);
    }

    else if (M == 64 && N == 64)//if matrix is 64x64
    {
        matrix_64x64(M, N, A, B);
    }

    else if (M == 61 && N == 67)//if matric is 61x67
    {
        //matrix_61x67(M, N, A, B);
        int i, j, k, l, temp;
        int size = 23;//divides matrix into 9 partitioned matrices fo 23x23
        for (i = 0; i < N; i += size)//choose section of rows in A to be copied
        {
            for (j = 0;  j < M; j += size)//choose section of columns in A to be copied
            {
                for (k = i; k < i + size && k < N; k++)//set row number in A to be copied
                {
                    for (l = j; l < j + size && l < M; l++)//set column number in A to be copied
                    {
                      if (k < 67 && l < 61)//as long as it is in bounds
                      {
                        temp = A[k][l];//put value of matrix A into t
                        B[l][k] = temp;//put value of t into transpose matrix B
                      }
                    }
                }
            }
        }
    }
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);

}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}
