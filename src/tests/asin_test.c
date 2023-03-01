#include "test_main.h"

static const double ASIN_EPS = 1e-16l;

START_TEST(test_asin_positive) {
  double x = 0.4;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), TEST_EPS);
}
END_TEST

START_TEST(test_asin_negative) {
  double x = -0.4;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), TEST_EPS);
}
END_TEST

START_TEST(test_asin_zero) {
  double x = 0;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), TEST_EPS);
}
END_TEST

START_TEST(test_asin_one) {
  double x = 1;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), TEST_EPS);
}
END_TEST

START_TEST(test_asin_one_negative) {
  double x = -1;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), TEST_EPS);
}
END_TEST

START_TEST(test_asin_huge_positive) {
  double x = 5;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(test_asin_huge_negative) {
  double x = -5;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(test_asin_big_mantissa) {
  double x = 0.123456789012345678901234567890;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), TEST_EPS);
}
END_TEST

START_TEST(test_asin_eps_positive) {
  double x = 1 + ASIN_EPS;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), TEST_EPS);
}
END_TEST

START_TEST(test_asin_eps_negative) {
  double x = -1 - ASIN_EPS;
  ck_assert_ldouble_eq_tol(asin(x), s21_asin(x), TEST_EPS);
}
END_TEST

START_TEST(test_asin_nan) {
  double x = S21_NAN;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

START_TEST(test_asin_inf) {
  double x = S21_INF;
  ck_assert_ldouble_nan(s21_asin(x));
}
END_TEST

Suite *suite_s21_asin(void) {
  Suite *s = suite_create("s21_asin");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_asin_positive);
  tcase_add_test(tc, test_asin_negative);
  tcase_add_test(tc, test_asin_zero);
  tcase_add_test(tc, test_asin_one);
  tcase_add_test(tc, test_asin_negative);
  tcase_add_test(tc, test_asin_one_negative);
  tcase_add_test(tc, test_asin_huge_positive);
  tcase_add_test(tc, test_asin_huge_negative);
  tcase_add_test(tc, test_asin_big_mantissa);
  tcase_add_test(tc, test_asin_eps_positive);
  tcase_add_test(tc, test_asin_eps_negative);
  tcase_add_test(tc, test_asin_nan);
  tcase_add_test(tc, test_asin_inf);

  suite_add_tcase(s, tc);
  return s;
}