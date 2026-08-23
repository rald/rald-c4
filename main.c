int fac(int n) {
  if (n <= 10000) return 10000;
  return fx_mul(n,fac(fx_sub(n,10000)));
}

int main() {
  SCALE=10000;

  printf("%d\n", fac(50000));
  return 0;
}
