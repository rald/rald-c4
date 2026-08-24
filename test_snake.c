// snake.c - Standalone Snake game for c4 with movement reversal prevention, custom colors, safe food spawn, and exit support

void draw_border() {
  int x;
  int y;
  
  // Use yellow text (33) on blue background (44) for the border walls
  setcolor_ext(1, 33, 44);

  x = 1;
  while (x <= 42) {
    gotoxy(x, 1);  putchar('-');
    gotoxy(x, 20); putchar('-');
    x = x + 1;
  }

  y = 2;
  while (y <= 19) {
    gotoxy(1, y);  putchar('|');
    gotoxy(42, y); putchar('|');
    y = y + 1;
  }

  gotoxy(1, 1);  putchar('+');
  gotoxy(42, 1); putchar('+');
  gotoxy(1, 20); putchar('+');
  gotoxy(42, 20);putchar('+');

  setcolor(37, 0);
}

int main() {
  int *x;
  int *y;
  int tail;
  int head;
  int dir;
  int foodx;
  int foody;
  int score;
  int gameover;
  int ch;
  int newx;
  int newy;
  int startx;
  int starty;
  int randdir;
  int i;
  int check_idx;
  int waiting_for_esc;
  int food_on_snake;

  fx_srand(time());

  x = malloc(8000);
  y = malloc(8000);

  tail = 0;
  head = 4;
  score = 0;
  gameover = 0;

  startx = 10 + (fx_rand() % 26);
  starty = 6 + (fx_rand() % 10);
  randdir = fx_rand() % 4;

  if (randdir == 0) {
    dir = 'R';
    x[0] = startx - 4;  y[0] = starty;
    x[1] = startx - 3;  y[1] = starty;
    x[2] = startx - 2;  y[2] = starty;
    x[3] = startx - 1;  y[3] = starty;
    x[4] = startx;      y[4] = starty;
  } else if (randdir == 1) {
    dir = 'L';
    x[0] = startx + 4;  y[0] = starty;
    x[1] = startx + 3;  y[1] = starty;
    x[2] = startx + 2;  y[2] = starty;
    x[3] = startx + 1;  y[3] = starty;
    x[4] = startx;      y[4] = starty;
  } else if (randdir == 2) {
    dir = 'U';
    x[0] = startx;  y[0] = starty + 4;
    x[1] = startx;  y[1] = starty + 3;
    x[2] = startx;  y[2] = starty + 2;
    x[3] = startx;  y[3] = starty + 1;
    x[4] = startx;  y[4] = starty;
  } else {
    dir = 'D';
    x[0] = startx;  y[0] = starty - 4;
    x[1] = startx;  y[1] = starty - 3;
    x[2] = startx;  y[2] = starty - 2;
    x[3] = startx;  y[3] = starty - 1;
    x[4] = startx;  y[4] = starty;
  }

  // Spawn initial food safely away from snake body
  food_on_snake = 1;
  while (food_on_snake) {
    foodx = 2 + (fx_rand() % 39);
    foody = 2 + (fx_rand() % 18);
    food_on_snake = 0;
    check_idx = tail;
    while (check_idx != head) {
      if (x[check_idx] == foodx && y[check_idx] == foody) {
        food_on_snake = 1;
      }
      check_idx = check_idx + 1;
      if (check_idx >= 1000) check_idx = 0;
    }
    if (x[head] == foodx && y[head] == foody) {
      food_on_snake = 1;
    }
  }

  clrscr();
  hide_cursor(); 
  draw_border(); 

  // Draw initial snake body segments (Yellow text on Green background)
  i = 0;
  while (i <= 4) {
    gotoxy(x[i], y[i]);
    setcolor_ext(1, 33, 42); // Yellow text (33), Green background (42)
    putchar('X');
    i = i + 1;
  }
  setcolor(37, 0);

  while (!gameover) {
    if (kbhit()) {
      ch = getch();
      if ((ch == 'w' || ch == 'W') && dir != 'D') dir = 'U';
      if ((ch == 's' || ch == 'S') && dir != 'U') dir = 'D';
      if ((ch == 'a' || ch == 'A') && dir != 'R') dir = 'L';
      if ((ch == 'd' || ch == 'D') && dir != 'L') dir = 'R';
      if (ch == 27) gameover = 1;
    }

    if (!gameover) {
      newx = x[head];
      newy = y[head];

      if (dir == 'U') newy = newy - 1;
      if (dir == 'D') newy = newy + 1;
      if (dir == 'L') newx = newx - 1;
      if (dir == 'R') newx = newx + 1;

      if (newx < 2)  newx = 41;
      if (newx > 41) newx = 2;
      if (newy < 2)  newy = 19;
      if (newy > 19) newy = 2;

      // Check collision with self
      check_idx = tail;
      while (check_idx != head) {
        if (x[check_idx] == newx && y[check_idx] == newy) {
          gameover = 1;
        }
        check_idx = check_idx + 1;
        if (check_idx >= 1000) check_idx = 0;
      }

      if (!gameover) {
        head = head + 1;
        if (head >= 1000) head = 0; 
        x[head] = newx;
        y[head] = newy;

        if (newx == foodx && newy == foody) {
          score = score + 1;
          // Spawn next food safely avoiding the snake
          food_on_snake = 1;
          while (food_on_snake) {
            foodx = 2 + (fx_rand() % 39);
            foody = 2 + (fx_rand() % 18);
            food_on_snake = 0;
            check_idx = tail;
            while (check_idx != head) {
              if (x[check_idx] == foodx && y[check_idx] == foody) {
                food_on_snake = 1;
              }
              check_idx = check_idx + 1;
              if (check_idx >= 1000) check_idx = 0;
            }
            if (x[head] == foodx && y[head] == foody) {
              food_on_snake = 1;
            }
          }
        } else {
          gotoxy(x[tail], y[tail]);
          putchar(' ');
          tail = tail + 1;
          if (tail >= 1000) tail = 0;
        }

        // Draw food: Yellow text on Red background (Yellow = 33, Red BG = 41)
        gotoxy(foodx, foody);
        setcolor_ext(1, 33, 41); 
        putchar('O');

        // Draw snake segment: Yellow text on Green background (Yellow = 33, Green BG = 42)
        gotoxy(newx, newy);
        setcolor_ext(1, 33, 42); 
        putchar('X');

        setcolor(37, 0);
        delay(120);
      }
    }
  }

  delay(2500);

  show_cursor(); 
  clrscr();
  print_str("Game Over! Final Score: ");
  print_int(score);
  putchar('\n');

  return 0;
}
