#ifndef TEST
#define TEST

#include <check.h>
#include <stdio.h>

#include "../s21_matrix.h"

Suite *suite_create(void);
Suite *suite_remove(void);
Suite *suite_eq(void);
Suite *suite_sum(void);
Suite *suite_sub(void);
Suite *suite_mult_number(void);
Suite *suite_mult(void);
Suite *suite_transpose(void);
Suite *suite_calc_complements(void);
Suite *suite_determinant(void);
Suite *suite_inverse(void);

#define ARRAY_SIZE 11
#define REGISTER_TESTS                                                  \
  suite_create(), suite_remove(), suite_eq(), suite_sum(), suite_sub(), \
      suite_mult_number(), suite_mult(), suite_transpose(),             \
      suite_calc_complements(), suite_determinant(), suite_inverse()
#endif  // TEST
