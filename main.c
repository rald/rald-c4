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
  char *buf;
  int bytes_read;
  
  msg = "Hello from c4 file writing and reading!\n";
  
  // 1. Write to output.txt (flags: 577 = O_WRONLY|O_CREAT|O_TRUNC, mode: 420 = 0644)
  fd = open("output.txt", 577, 420);
  if (fd < 0) {
    printf("Error opening file for writing\n");
    return -1;
  }
  
  write(fd, msg, strlen(msg));
  close(fd);
  printf("Successfully wrote to output.txt\n");
  
  // 2. Read back from output.txt
  buf = malloc(100); 
  
  // Notice the 3 arguments: filename, flags (0 = O_RDONLY), dummy mode (0)
  fd = open("output.txt", 0, 0);
  if (fd < 0) {
    printf("Error opening file for reading\n");
    return -1;
  }
  
  bytes_read = read(fd, buf, 99);
  close(fd);
  
  if (bytes_read > 0) {
    buf[bytes_read] = 0;
    
    printf("--- Contents read from output.txt ---\n");
    printf("%s", buf);
  } else {
    printf("No data read from file.\n");
  }
  
  free(buf);
  return 0;
}
