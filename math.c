#include <stdio.h>

int SCALE;
int next_seed;

// Set the seed for the random number generator
int fx_srand(int seed) {
  next_seed = seed;
  return 0;
}

// Generate a pseudo-random fixed-point/integer number
int fx_rand() {
  int res; // Declaration

  // LCG parameters (values from Numerical Recipes)
  next_seed = (next_seed * 1103515245 + 12345);
  res = next_seed & 2147483647; // Initialization

  return res;
}

int fx_add(int a, int b) {
  int result; // Declaration
  result = a + b; // Initialization
  return result;
}

int fx_sub(int a, int b) {
  int result; // Declaration
  result = a - b; // Initialization
  return result;
}

int fx_mul(int a, int b) {
  int result; // Declaration
  result = (a * b) / SCALE; // Initialization
  return result;
}

int fx_div(int a, int b) {
  int result; // Declaration
  result = (a * SCALE) / b; // Initialization
  return result;
}

// 1. Truncate
int fx_trunc(int a) {
  int res; // Declaration
  res = (a / SCALE) * SCALE; // Initialization
  return res;
}

// 2. Floor (rounds down toward negative infinity)
int fx_floor(int a) {
  int res; // Declaration
  int rem; // Declaration

  res = a / SCALE; // Initialization
  rem = a % SCALE; // Initialization

  if (rem != 0 && ((a < 0) ^ (SCALE < 0))) {
    res = res - 1;
  }

  return res * SCALE;
}

// 3. Ceil (rounds up toward positive infinity)
int fx_ceil(int a) {
  int res; // Declaration
  int rem; // Declaration

  res = a / SCALE; // Initialization
  rem = a % SCALE; // Initialization

  if (rem != 0 && !((a < 0) ^ (SCALE < 0))) {
    res = res + 1;
  }

  return res * SCALE;
}

// 4. Round (rounds to the nearest integer)
int fx_round(int a) {
  int res; // Declaration

  if (a >= 0) {
    res = (a + SCALE / 2) / SCALE * SCALE; // Initialization
  } else {
    res = (a - SCALE / 2) / SCALE * SCALE; // Initialization
  }

  return res;
}

int main() {
  int a; // Declaration
  int b; // Declaration
  int i; // Declaration
  int r; // Declaration

  SCALE = 10000; // 4 decimal places of precision

  // Initialize random seed
  fx_srand(42);

  printf("--- Testing Random Number Generation ---\n");
  i = 0; // Initialization
  while (i < 5) {
    r = fx_rand() % (SCALE * 5); // Initialization
    printf("Random value %d: %lld\n", i, r);
    i = i + 1;
  }

  return 0;
}
