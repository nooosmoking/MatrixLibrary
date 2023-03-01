#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;
  int flag_break = 1, flag = 0;
  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  if (is_nan(x)) {
    result = x < 0 ? -S21_NAN : S21_NAN;
  } else if (is_inf(x)) {
    result = x < 0 ? 0 : S21_INF;
  } else {
    long double factorial = 1;
    long double step = 1;
    while (s21_fabs(step) > 1e-100 && flag_break) {
      step *= x / factorial;
      result += step;
      factorial++;
      if (result > S21_MAX_LD) {
        result = S21_INF;
        flag_break = 0;
      }
    }
  }
  if (flag == 1) {
    if (result > S21_MAX_LD)
      result = 0;
    else
      result = 1. / result;
  }
  return result;
}