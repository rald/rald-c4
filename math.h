int SCALE;

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

// Modulo operation for fixed-point numbers
int fx_mod(int a, int b) {
  int result; // Declaration
  result = a % b; // Initialization
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

// Calculate fixed-point factorial (n!)
int fx_fact(int n) {
  int result;
  int i;
  
  // 1.0 in fixed-point representation is SCALE
  result = SCALE; 
  i = 1;

  while (i <= n) {
    // Multiply result by current integer/fixed-point factor
    result = fx_mul(result, i * SCALE);
    i = i + 1;
  }

  return result;
}

// Calculate fixed-point power (base^exp) where exp is an integer
int fx_pow(int base, int exp) {
  int result;
  int i;

  // 1.0 in fixed-point representation is SCALE
  result = SCALE;
  i = 0;

  if (exp < 0) {
    // Simple handling for negative exponents can be expanded if needed,
    // but for basic integer exponents:
    return 0; 
  }

  while (i < exp) {
    result = fx_mul(result, base);
    i = i + 1;
  }

  return result;
}