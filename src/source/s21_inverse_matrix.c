#include "s21_math.h"

long double exmp1(long double x) {
  if (s21_fabs(x) < S21_EPS)
    return x + x * x / 2;
  else
    return (long double)(s21_exp(x) - 1);
}

long double s21_log(double x) {
  long double res = 0;
  short int invert = x > 1;
  if (is_nan(x) || is_inf(x)) {
    if (x == -S21_INF)
      res = -S21_NAN;
    else
      res = x;
  } else if (x < 0) {
    res = S21_NAN;
  } else if (x == 0) {
    res = -S21_INF;
  } else {
    long double lx = 0;
    if (invert)
      lx = 1 / x;
    else
      lx = x;

    long double y = 0;
    long double expy = 1.;
    long double ydiff = y - 1.;

    while (s21_fabs(ydiff) > S21_EPS) {
      expy += expy * exmp1(-ydiff);
      y += ydiff;
      ydiff = lx * expy - 1.;
    }
    res += y;
    if (invert) res = -res;
  }
  return res;
}
