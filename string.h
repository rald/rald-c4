int strlen(char *s) {
  char *p;
  p = s;
  while (*s) {
    s = s + 1;
  }
  return s - p;
}

char *strcpy(char *dest, char *src) {
  char *d;
  d = dest;
  while (*src) {
    *d = *src;
    d = d + 1;
    src = src + 1;
  }
  *d = 0;
  return dest;
}

int strcmp(char *s1, char *s2) {
  while (*s1 && *s1 == *s2) {
    s1 = s1 + 1;
    s2 = s2 + 1;
  }
  return *s1 - *s2;
}

char *strcat(char *dest, char *src) {
  char *d;
  d = dest;
  while (*d) {
    d = d + 1;
  }
  while (*src) {
    *d = *src;
    d = d + 1;
    src = src + 1;
  }
  *d = 0;
  return dest;
}

char *strupr(char *s) {
  char *p;
  p = s;
  while (*s) {
    *s = toupper(*s);
    s = s + 1;
  }
  return p;
}

char *strlwr(char *s) {
  char *p;
  p = s;
  while (*s) {
    *s = tolower(*s);
    s = s + 1;
  }
  return p;
}

char *strrev(char *s) {
  char *p;
  char *q;
  char temp;
  
  if (!s) return s;
  
  p = s;
  q = s;
  
  while (*q) {
    q = q + 1;
  }
  
  if (q > s) {
    q = q - 1;
  }
  
  while (p < q) {
    temp = *p;
    *p = *q;
    *q = temp;
    p = p + 1;
    q = q - 1;
  }
  
  return s;
}