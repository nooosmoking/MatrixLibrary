#ifndef TEST

#define TEST

#include <check.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_math.h"

#define TEST_EPS 1e-6l

// jenegabr
Suite *suite_s21_acos(void);
Suite *suite_s21_asin(void);
Suite *suite_s21_atan(void);
Suite *suite_s21_ceil(void);

// kaleighh
Suite *suite_s21_abs(void);
Suite *suite_s21_fmod(void);
Suite *suite_s21_pow(void);
Suite *suite_s21_sin(void);

// griffinp
Suite *suite_s21_cos(void);
Suite *suite_s21_exp(void);
Suite *suite_s21_fabs(void);
Suite *suite_s21_floor(void);

// // netromnik
Suite *suite_s21_log(void);
Suite *suite_s21_sqrt(void);
Suite *suite_s21_tan(void);

#define ARRAY_SIZE 15
#define REGISTER_TESTS                                                     \
  suite_s21_acos(), suite_s21_asin(), suite_s21_atan(), suite_s21_ceil(),  \
      suite_s21_abs(), suite_s21_fmod(), suite_s21_pow(), suite_s21_sin(), \
      suite_s21_log(), suite_s21_sqrt(), suite_s21_tan(), suite_s21_cos(), \
      suite_s21_exp(), suite_s21_fabs(), suite_s21_floor()
#endif  // TEST
