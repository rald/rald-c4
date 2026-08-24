// test_ctype.c - Test suite for ctype.h functions in c4

int main() {
  char *s;
  int i;
  int c;

  // Test isdigit
  printf("--- Testing isdigit ---\n");
  s = "a1b2c3";
  i = 0;
  while (i < 6) {
    c = s[i];
    printf("isdigit('%c') = %d\n", c, isdigit(c));
    i = i + 1;
  }

  // Test isalpha
  printf("--- Testing isalpha ---\n");
  s = "A1_z!";
  i = 0;
  while (i < 5) {
    c = s[i];
    printf("isalpha('%c') = %d\n", c, isalpha(c));
    i = i + 1;
  }

  // Test isalnum
  printf("--- Testing isalnum ---\n");
  s = "A1_z!";
  i = 0;
  while (i < 5) {
    c = s[i];
    printf("isalnum('%c') = %d\n", c, isalnum(c));
    i = i + 1;
  }

  // Test isspace
  printf("--- Testing isspace ---\n");
  s = " \t\nxy";
  i = 0;
  while (i < 5) {
    c = s[i];
    if (c == '\n') {
      printf("isspace('\\n') = %d\n", isspace(c));
    } else if (c == '\t') {
      printf("isspace('\\t') = %d\n", isspace(c));
    } else {
      printf("isspace('%c') = %d\n", c, isspace(c));
    }
    i = i + 1;
  }

  // Test toupper and tolower
  printf("--- Testing toupper and tolower ---\n");
  c = 'a';
  printf("toupper('%c') = '%c'\n", c, toupper(c));
  c = 'Z';
  printf("tolower('%c') = '%c'\n", c, tolower(c));

  return 0;
}
