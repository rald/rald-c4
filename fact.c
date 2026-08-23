int fact(int n) {
  int i,j;
  i=n;
  j=1;
  while(i>1) {
    j=j*i;
    i=i-1;
  }
  return j;
}

int main() {

  printf("%lld\n",fact(20));

  return 0;
}
