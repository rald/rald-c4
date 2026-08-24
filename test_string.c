// strings.c - Test suite for string.h in c4 using malloc

int main() {
  char *dest;
  char *src;
  int len;
  int cmp;

  dest = malloc(64);

  // Test strlen
  src = "Hello, C4!";
  len = strlen(src);
  printf("strlen(\"%s\") = %d\n", src, len);

  // Test strcpy
  strcpy(dest, src);
  printf("strcpy result: \"%s\"\n", dest);

  // Test strcmp
  cmp = strcmp("aa", "bb");
  printf("strcmp(\"aa\", \"bb\") = %d\n", cmp);

  cmp = strcmp("aa", "aa");
  printf("strcmp(\"aa\", \"aa\") = %d\n", cmp);

  cmp = strcmp("bb", "aa");
  printf("strcmp(\"bb\", \"aa\") = %d\n", cmp);

  // Test strcat
  strcpy(dest, "Hello ");
  strcat(dest, "World!");
  printf("strcat result: \"%s\"\n", dest);

  // Test strupr
  strcpy(dest, "Hello C4 Upper!");
  strupr(dest);
  printf("strupr result: \"%s\"\n", dest);

  // Test strlwr
  strcpy(dest, "HELLO C4 LOWER!");
  strlwr(dest);
  printf("strlwr result: \"%s\"\n", dest);

  free(dest);
  return 0;
}
