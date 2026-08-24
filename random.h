int next_seed;

// Set the seed for the random number generator
int srand(int seed) {
  next_seed = seed;
  return 0;
}

// Generate a pseudo-random fixed-point/integer number
int rand() {
  int res; // Declaration

  // LCG parameters (values from Numerical Recipes)
  next_seed = (next_seed * 1103515245 + 12345);
  res = next_seed & 2147483647; // Initialization

  return res;
}
