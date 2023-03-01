#include "s21_math.h"

long double s21_floor(double x) {
  long double result = 0;
  if (is_nan(x)) {
    result = x < 0 ? -S21_NAN : S21_NAN;
  } else if (is_inf(x)) {
    result = x < 0 ? -S21_INF : S21_INF;
  } else {
    result = (long double)((int)x);
  }
  return (result != x && x < 0) ? (result - 1) : result;
}