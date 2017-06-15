//eruiz, suzoegwu

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
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{

//ints to be used to navigate through the cache
  int i, j, column, row, z;

//if the cache is a 32 x 32, execute this
  if (N == 32 && M == 32){
    for (column = 0; column < N; column +=8){
      for (row = 0; row < N; row += 8) {
        for(i = row; i < row + 8; i++){
          for(j = column; j < column + 8; j++){
            //if I am not on the diagonal, swap the matrix to the opposite end
            if(i != j){
              z = A[i][j];
              B[j][i] = z;
            }
          }
          //If I am on the diagonal, copy the element over to the exact position
          if(row == column){
            z = A[i][i];
            B[i][i] = z;
          }
        }
      }
    }
  }


//if the cache is a 64 x 64, execute this
  if(N == 64 && M == 64){
    for (column = 0; column < N; column +=4){
      for (row = 0; row < N; row += 4) {
        for(i = row; i < row + 4; i++){
          for(j = column; j < column + 4; j++){
            //if I am not on the diagonal, swap the matrix to the opposite end
            if(i != j){
              z = A[i][j];
              B[j][i] = z;
            }
          }
          //If I am on the diagonal, copy the element over to the exact position
          if(row == column){
            z = A[i][i];
            B[i][i] = z;
          }
        }
      }
    }
  }

//if the cache is a 61 x 67, execute this
  if(M==61 && N==67){
    for (row =0; row < N; row += 18){
      for(column = 0; column < M; column += 18){
        for(i=row; i< row + 18 && i<N; i++){
          for(j=column; j<column+18 && j<M; j++){
            //swap the elements with the one in the opposite position
            z = A[i][j];
            B[j][i] = z;
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
