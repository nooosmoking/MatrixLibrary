#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 0;
  int equal = 1;
  if (A->rows > 0 && A->columns > 0 && B->rows > 0 && B->columns > 0 &&
      A->matrix && B->matrix && A->rows == B->rows &&
      A->columns == B->columns) {
    for (int i = 0; i < A->rows && equal; i++) {
      for (int j = 0; j < A->columns && equal; j++)
        if (A->matrix[i][j] - B->matrix[i][j] > 1e-7) equal = 0;
    }
    status = equal;
  }
  return status;
}