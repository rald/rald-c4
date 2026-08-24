// snake.c - Snake game with screen wrapping for c4

void hide_cursor() {
  putchar(27);
  print_str("[?25l");
}

void show_cursor() {
  putchar(27);
  print_str("[?25h");
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

  // Allocate memory for 100 coordinates (800 bytes each)
  x = malloc(800);
  y = malloc(800);

  // Initialize game state
  tail = 0;
  head = 4;
  dir = 'R'; // Right direction initially
  score = 0;
  gameover = 0;

  // Initial snake body positions
  x[0] = 5;  y[0] = 5;
  x[1] = 6;  y[1] = 5;
  x[2] = 7;  y[2] = 5;
  x[3] = 8;  y[3] = 5;
  x[4] = 9;  y[4] = 5;

  // Initial food position
  foodx = 15;
  foody = 10;

  clrscr();
  hide_cursor(); // Hide blinking text cursor during gameplay

  while (!gameover) {
    // Check for keyboard input non-blockingly
    if (kbhit()) {
      ch = getch();
      if (ch == 'w' || ch == 'W') dir = 'U';
      if (ch == 's' || ch == 'S') dir = 'D';
      if (ch == 'a' || ch == 'A') dir = 'L';
      if (ch == 'd' || ch == 'D') dir = 'R';
      if (ch == 'q' || ch == 'Q') gameover = 1;
    }

    // Calculate new head position
    newx = x[head];
    newy = y[head];

    if (dir == 'U') newy = newy - 1;
    if (dir == 'D') newy = newy + 1;
    if (dir == 'L') newx = newx - 1;
    if (dir == 'R') newx = newx + 1;

    // Screen wrapping logic (40 width, 20 height grid)
    if (newx < 1)  newx = 40;
    if (newx > 40) newx = 1;
    if (newy < 1)  newy = 20;
    if (newy > 20) newy = 1;

    // Move snake head forward
    head = head + 1;
    x[head] = newx;
    y[head] = newy;

    // Check if food eaten
    if (newx == foodx && newy == foody) {
      score = score + 1;
      // Spawn new food using pseudo-random generation based on score
      foodx = 5 + (score * 3) % 30;
      foody = 5 + (score * 2) % 12;
    } else {
      // Clear tail if no food eaten
      gotoxy(x[tail], y[tail]);
      putchar(' ');
      tail = tail + 1;
    }

    // Draw food and snake head
    gotoxy(foodx, foody);
    setcolor(32, 0); // Green food
    putchar('O');

    gotoxy(newx, newy);
    setcolor(36, 0); // Cyan snake head
    putchar('#');

    // Reset color and delay frame (~120ms)
    setcolor(37, 0);
    delay(120);
  }

  show_cursor(); // Restore cursor visibility before exit
  clrscr();
  print_str("Game Over! Final Score: ");
  print_int(score);
  putchar('\n');
  return 0;
}
