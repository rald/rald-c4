#include <stdio.h>

int SCALE;

int fx_add(int a, int b) {
  int result;
  result = a + b;
  return result;
}

int fx_sub(int a, int b) {
  int result;
  result = a - b;
  return result;
}

int fx_mul(int a, int b) {
  int result;
  result = (a * b) / SCALE;
  return result;
}

int fx_div(int a, int b) {
  int result;
  result = (a * SCALE) / b;
  return result;
}

// 1. Truncate
int fx_trunc(int a) {
  int res;
  res = (a / SCALE) * SCALE;
  return res;
}

// 2. Floor (rounds down toward negative infinity)
int fx_floor(int a) {
  int res;
  int rem;
  
  res = a / SCALE;
  rem = a % SCALE;
  
  if (rem != 0 && ((a < 0) ^ (SCALE < 0))) {
    res = res - 1;
  }
  
  return res * SCALE;
}

// 3. Ceil (rounds up toward positive infinity)
int fx_ceil(int a) {
  int res;
  int rem;
  
  res = a / SCALE;
  rem = a % SCALE;
  
  if (rem != 0 && !((a < 0) ^ (SCALE < 0))) {
    res = res + 1;
  }
  
  return res * SCALE;
}

// 4. Round (rounds to the nearest integer)
int fx_round(int a) {
  int res;
  
  if (a >= 0) {
    res = (a + SCALE / 2) / SCALE * SCALE;
  } else {
    res = (a - SCALE / 2) / SCALE * SCALE;
  }
  
  return res;
}

int main() {
  int a;
  int b;
  
  SCALE = 10000; // 4 decimal places of precision

  // Representing 2.5342 and -2.5342
  a = 25342;  // 2.5342 * 10000
  b = -25342; // -2.5342 * 10000

  printf("--- Testing with Positive (2.5342) ---\n");
  printf("Trunc: %lld\n", fx_trunc(a));
  printf("Floor: %lld\n", fx_floor(a));
  printf("Ceil:  %lld\n", fx_ceil(a));
  printf("Round: %lld\n", fx_round(a));

  printf("\n--- Testing with Negative (-2.5342) ---\n");
  printf("Trunc: %lld\n", fx_trunc(b));
  printf("Floor: %lld\n", fx_floor(b));
  printf("Ceil:  %lld\n", fx_ceil(b));
  printf("Round: %lld\n", fx_round(b));

  return 0;
}