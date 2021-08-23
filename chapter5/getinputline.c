#include <stdio.h>
// 1_9
// getinputline: read a line into s, return length
int getinputline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  // 字符数组以\0结尾
  s[i] = '\0';
  return i;
}