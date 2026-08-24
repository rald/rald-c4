// test_math.c - Test suite for fixed-point math library compatible with c4.c

void main() {
  int a,b;
  int val;

  // Initialize scale factor (e.g., 1000 for 3 decimal places)
  SCALE = 1000;

  printf("Starting Math Library Tests...\n");

  // Test basic arithmetic
  a = 2500; // Represents 2.5
  b = 1500; // Represents 1.5

  printf("Add test: %d + %d = %d\n", a, b, fx_add(a, b));
  printf("Sub test: %d - %d = %d\n", a, b, fx_sub(a, b));
  printf("Mul test: %d * %d = %d\n", a, b, fx_mul(a, b));
  printf("Div test: %d / %d = %d\n", a, b, fx_div(a, b));

  // Test rounding operations on a mixed value like 2700 (2.7)
  val = 2700;
  printf("Value: %d\n", val);
  printf("Trunc: %d\n", fx_trunc(val));
  printf("Floor: %d\n", fx_floor(val));
  printf("Ceil:  %d\n", fx_ceil(val));
  printf("Round: %d\n", fx_round(val));

  // Test PRNG
  fx_srand(42);
  printf("Rand 1: %d\n", fx_rand());
  printf("Rand 2: %d\n", fx_rand());

  printf("Math Library Tests Completed Successfully.\n");
}
