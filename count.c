#include <stdio.h>

int main() {

  int i;

  i = 0;
  while(i < 1000000) {
    printf("%d\n", i);
    i=i+1;
  }

  return 0;
}
