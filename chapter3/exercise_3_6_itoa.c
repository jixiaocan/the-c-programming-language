#include <limits.h>
#include <stdio.h>

#include "3_5_reverse.c"

#define abs(x) ((x) < 0 ? -(x) : (x))

void itoa(int n, char s[], int w);

int main() {
  int n = -12345;
  char s[15];

  for (int i = 0; i < 10; i++) {
    s[i] = 0;
  }
  itoa(n, s, 10);
  printf("%s\n", s);

  n = INT_MIN;

  itoa(n, s, 10);
  // 可以处理最小值的情况
  printf("%s\n", s);
}

/* itoa: convert n to characters in s, w characters wide */
void itoa(int n, char s[], int w) {
  int i, sign;

  i = 0;
  sign = n;
  /* generate digits in reverse order */
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0); // 注意 while 条件变成了 != 0
  if (sign < 0) {
    s[i++] = '-';
  }
  while(i < w)
    s[i++] =' '; // pad with blanks
  s[i] = '\0';
  reverse(s);
}