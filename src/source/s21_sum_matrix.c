#include "s21_math.h"

long double s21_atan(double x) {
  long double result = 0;
  const long double atan_1 = 0.7853981633974480L;

  if (is_nan(x)) {
    return S21_NAN;
  }
  if (x == 1)
    result = atan_1;
  else if (x == -1)
    result = -atan_1;
  else if (x == S21_PI / 2) {
    result = 1.003884821853887214L;
  } else if (x == -S21_PI / 2) {
    result = -1.003884821853887214L;
  } else if (x == S21_INF || x == -S21_INF) {
    result = x < 0 ? -S21_PI / 2 : S21_PI / 2;
  } else if (x > -1. && x < 1.) {
    for (register int i = 0; i < ACCURACY; ++i) {
      result += (s21_pow(-1, i) * s21_pow(x, 2 * i + 1)) / (2 * i + 1);
    }
  } else {
    x = 1. / x;
    for (register int i = 0; i < ACCURACY; ++i) {
      result += (s21_pow(-1, i) * s21_pow(x, 2 * i + 1)) / (2 * i + 1);
    }
    if (x > 0.)
      result += (-S21_PI / 2);
    else
      result += (S21_PI / 2);

    result = -result;
  }
  return result;
}
