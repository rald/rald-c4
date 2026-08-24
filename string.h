int strlen(char *s) {
  char *p;
  p = s;
  while (*s) {
    s = s + 1;
  }
  return s - p;
}
