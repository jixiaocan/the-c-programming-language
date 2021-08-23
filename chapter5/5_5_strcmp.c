#include <stdio.h>

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp0(char *s, char *t) {
  int i;
  for (i = 0; s[i] == t[i]; i++)
    if (s[i] == '\0') return 0;
  return s[i] - t[i];
}

int strcmp1(char *s, char *t) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0') return 0;
  }
  return *s - *t;
}