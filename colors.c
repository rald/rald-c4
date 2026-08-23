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

void main()
{
  int ch;
  int t;
  int b;
  int x_pos;
  int y_pos;
  int current_attr;

  clrscr();
  
  // Title Header
  setcolor(33, 40);
  gotoxy(3, 2);
  print_str("=== ANSI Matrix (Underlined Identical FG/BG) ===");

  t = 30;
  while (t <= 37) {
    b = 40;
    while (b <= 47) {
      x_pos = (b - 40) * 9 + 3;
      y_pos = (t - 30) * 2 + 5;

      // Default attribute is normal (0)
      current_attr = 0;

      // If FG and BG match, apply Underline (4) so the text stays visible 
      // while preserving its exact true color!
      if ((t - 30) == (b - 40)) {
        current_attr = 4; 
      }

      gotoxy(x_pos, y_pos);
      setcolor_ext(current_attr, t, b);
      print_str("T");
      print_int(t);
      print_str(" B");
      print_int(b);

      b = b + 1;
    }
    t = t + 1;
  }

  // Reset colors and place exit prompt at the bottom
  setcolor(37, 40);
  gotoxy(3, 23);
  print_str("Type anything to exit (Ctrl+D): ");

  while ((ch = getchar()) != -1) {
    putchar(ch);
  }
  
  setcolor(37, 40);
  clrscr();
}
