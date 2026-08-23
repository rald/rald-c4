int strlen(char *s) {
  char *p;
  p = s;
  while (*s) {
    s = s + 1;
  }
  return s - p;
}

int main() {
  int fd;
  char *msg;
  
  msg = "Hello from c4 with custom open permissions and strlen!\n";
  
  // open(filename, flags, mode)
  // flags: 577 (O_WRONLY | O_CREAT | O_TRUNC)
  // mode:  420 (0644 in decimal)
  fd = open("output.txt", 577, 420);
  if (fd < 0) {
    printf("Error opening file for writing\n");
    return -1;
  }
  
  write(fd, msg, strlen(msg));
  close(fd);
  
  printf("Successfully created output.txt with 644 permissions (length: %d)\n", strlen(msg));
  return 0;
}
