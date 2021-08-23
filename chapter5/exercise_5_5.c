// copy n characters from t to s
void strncpy(char *s, char *t, int n) {
  while (*t && n-- > 0) {
    *s++ = *t++;
  }
  // 不足 n个字符，使用 \0 填充
  while (n-- > 0) {
    *s++ = '\0';
  }
}

// concatenate n char of t to the end of
void strncat(char *s, char *t, int n) {
  void strncpy(char *s, char *t, int n);
  int strlen(char *);

  stncpy(s + strlen(s), t, n);
}

// compare at most n characters of t with s
int strncmp(char *s, char *t, int n) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0'|| --n <= 0) return 0;
  }
  return *s - *t;
}