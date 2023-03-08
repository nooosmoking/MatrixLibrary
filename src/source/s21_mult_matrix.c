#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = 0;
  if (A->rows <= 0 && A->columns <= 0 && B->rows <= 0 && B->columns <= 0 &&
      !(A->matrix) && !(B->matrix)) {
    status = 1;
  } else if (A->columns != B->rows) {
    status = 2;
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        for (int k = 0; k < B->rows; k++)
          result->matrix[i][j] =
              result->matrix[i][j] + A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return status;
}