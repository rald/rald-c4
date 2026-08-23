int SCALE;

int fx_add(int a, int b) {
  return a + b;
}

int fx_sub(int a, int b) {
  return a - b;
}

int fx_mul(int a, int b) {
  return (a * b) / SCALE;
}

int fx_div(int a, int b) {
  return (a * SCALE) / b;
}

int main() {
  int a,b;

  SCALE = 10000; // 4 decimal places of precision

  // Representing 2.5342 and 1.1234
  a = 25342; // 2.5342 * 10000
  b = 11234; // 1.1234 * 10000

  // Addition: 2.5342 + 1.1234 = 3.6576
  printf("Add: %lld + %lld = %lld\n", a, b, fx_add(a, b));

  // Subtraction: 2.5342 - 1.1234 = 1.4108
  printf("Sub: %lld - %lld = %lld\n", a, b, fx_sub(a, b));

  // Multiplication: 2.5342 * 1.1234 ≈ 2.8479
  printf("Mul: %lld * %lld = %lld\n", a, b, fx_mul(a, b));

  // Division: 2.5342 / 1.1234 ≈ 2.2558
  printf("Div: %lld / %lld = %lld\n", a, b, fx_div(a, b));

  return 0;
}
