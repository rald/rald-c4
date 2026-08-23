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

void print_str(char *s)
{
  int idx;
  idx = 0;
  while (s[idx] != 0) {
    putchar(s[idx]);
    idx = idx + 1;
  }
}

void print_int(int n)
{
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / 10) {
    print_int(n / 10);
  }
  putchar((n % 10) + '0');
}

void clrscr()
{
  putchar(27);
  print_str("[2J");
  putchar(27);
  print_str("[H");
}

void gotoxy(int x, int y)
{
  putchar(27);
  print_str("[");
  print_int(y);
  putchar(';');
  print_int(x);
  print_str("H");
}

// Enhanced setcolor supporting an extra attribute (like Underline = 4 or Bold = 1)
void setcolor_ext(int attr, int text_code, int bg_code)
{
  putchar(27);
  print_str("[");
  print_int(attr);
  putchar(';');
  print_int(text_code);
  putchar(';');
  print_int(bg_code);
  print_str("m");
}

void setcolor(int text_code, int bg_code)
{
  setcolor_ext(0, text_code, bg_code);
}
