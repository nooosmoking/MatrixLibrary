#include "test_main.h"

START_TEST(test_zero_abs) { ck_assert_int_eq(abs(0), s21_abs(0)); }
END_TEST

START_TEST(test_neg_abs) { ck_assert_int_eq(abs(-1234), s21_abs(-1234)); }
END_TEST

START_TEST(test_pos_abs) { ck_assert_int_eq(abs(1234), s21_abs(1234)); }
END_TEST

Suite *suite_s21_abs(void) {
  Suite *s = suite_create("s21_abs");
  TCase *tc = tcase_create("core");

  tcase_add_test(tc, test_zero_abs);
  tcase_add_test(tc, test_neg_abs);
  tcase_add_test(tc, test_pos_abs);

  suite_add_tcase(s, tc);
  return s;
}