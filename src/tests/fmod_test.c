#include "test_main.h"

START_TEST(test_pos_fmod) {
  double x = 534536.34523;
  double y = 2345.34535;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}
END_TEST

START_TEST(test_neg_fmod) {
  double x = -5345346.34523;
  double y = 2345.34535;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}
END_TEST

START_TEST(test_neg2_fmod) {
  double x = 5345346.34523;
  double y = -2345.34535;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}
END_TEST

START_TEST(test_neg_two_fmod) {
  double x = -10.1;
  double y = -3.;
  ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}

START_TEST(test_nul_fmod) {
  double x = 5345346.34523;
  double y = 0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(test_nul2_fmod) {
  double x = 0;
  double y = 4353.64564;
  ck_assert_double_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}
END_TEST

START_TEST(test_nul3_fmod) {
  double x = 0;
  double y = -S21_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(test_nan_fmod) {
  double x = S21_NAN;
  double y = 245.34535;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(test_nan2_fmod) {
  double x = 245.34535;
  double y = S21_NAN;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(test_inf_fmod) {
  double x = S21_INF;
  double y = 4323.432543;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(test_inf2_fmod) {
  double x = 436645.34523;
  double y = S21_INF;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}
END_TEST

START_TEST(test_inf3_fmod) {
  double x = 436645.34523;
  double y = -S21_INF;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}
END_TEST

START_TEST(test_inf4_fmod) {
  double x = -S21_INF;
  double y = 0;
  ck_assert_ldouble_nan(s21_fmod(x, y));
}
END_TEST

START_TEST(test_inf5_fmod) {
  double x = 0;
  double y = S21_INF;
  ck_assert_ldouble_eq_tol(fmod(x, y), s21_fmod(x, y), TEST_EPS);
}
END_TEST

Suite *suite_s21_fmod(void) {
  Suite *s = suite_create("s21_fmod");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_pos_fmod);
  tcase_add_test(tc, test_neg_fmod);
  tcase_add_test(tc, test_neg2_fmod);
  tcase_add_test(tc, test_neg_two_fmod);
  tcase_add_test(tc, test_nul_fmod);
  tcase_add_test(tc, test_nul2_fmod);
  tcase_add_test(tc, test_nul3_fmod);
  tcase_add_test(tc, test_nan_fmod);
  tcase_add_test(tc, test_nan2_fmod);
  tcase_add_test(tc, test_inf_fmod);
  tcase_add_test(tc, test_inf2_fmod);
  tcase_add_test(tc, test_inf3_fmod);
  tcase_add_test(tc, test_inf4_fmod);
  tcase_add_test(tc, test_inf5_fmod);
  suite_add_tcase(s, tc);
  return s;
}