#include "s21_math.h"

long double s21_cos(double x) {
  long double result = 1;
  if (!is_inf(x) && !is_nan(x)) {
    x = s21_fmod(x, 2 * S21_PI);
    long double factorial = 1;
    long double step = 1;
    while (s21_fabs(step) > 1e-6l) {
      step *= -x * x / ((2 * factorial - 1) * (2 * factorial));
      result += step;
      factorial++;
    }
  } else {
    result = S21_NAN;
  }
  return result;
}