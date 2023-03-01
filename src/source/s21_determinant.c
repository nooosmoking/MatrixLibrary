#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = S21_NAN;
  if (!is_inf(x) && !is_nan(x) && !is_nan(y) && !is_inf(y) && y != 0) {
    double quot = 0.;
    if ((x < 0 && y > 0) || (x > 0 && y < 0))
      quot = s21_ceil(x / y);
    else
      quot = s21_floor(x / y);
    long double no_rem = y * quot;
    res = x - no_rem;
  } else if (!is_inf(x) && is_inf(y)) {
    res = x;
  }
  return res;
}
