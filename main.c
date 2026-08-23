int getchar()
{
  char c;
  if (read(0, &c, 1) <= 0) return -1;
  return c;
}

int putchar(char c)
{
  write(1, &c, 1);
  return c;
}

void main()
{
  int c;
  // Echo loop: reads from stdin and writes to stdout until EOF
  while ((c = getchar()) != -1) {
    putchar(c);
  }
}
