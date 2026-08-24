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
  print_str("=== ANSI Matrix FG/BG COLORS ===");

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
