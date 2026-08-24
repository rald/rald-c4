int fputs(char *s, int fd) {
  int len;
  
  len = 0;
  while (s[len] != 0) {
    len = len + 1;
  }
  
  return write(fd, s, len);
}

int fgets(char *s, int size, int fd) {
  int i;
  int n;
  char c;
  int running;
  
  if (size <= 0) {
    return 0;
  }
  
  i = 0;
  running = 1;
  while (running) {
    if (i >= size - 1) {
      running = 0;
    } else {
      n = read(fd, &c, 1);
      if (n <= 0) {
        if (i == 0) {
          return 0;
        }
        running = 0;
      } else {
        // Handle Backspace (ASCII 127 or 8)
        if (c == 127 || c == 8) {
          if (i > 0) {
            i = i - 1;
            // Erase character visually: move back, write space, move back again
            putch(8);
            putch(32);
            putch(8);
          }
        } else {
          // Manually echo each typed character to the screen
          write(1, &c, 1);
          
          s[i] = c;
          i = i + 1;
          if (c == '\n') {
            running = 0;
          }
        }
      }
    }
  }
  
  s[i] = 0;
  return s;
}

int main() {
  char *name;
  int len;

  name = malloc(64);

  write(1, "Enter your name: ", 17);
  if (fgets(name, 64, 0)) {
    // Remove newline character if present for clean printing
    len = 0;
    while (name[len] != 0) {
      if (name[len] == '\n') {
        name[len] = 0;
      }
      len = len + 1;
    }

    fputs("Hello, ", 1);
    fputs(name, 1);
    fputs("\n", 1);
  }

  return 0;
}
