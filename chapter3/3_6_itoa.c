#include <stdio.h>
#include <limits.h>
#include "3_5_reverse.c"

void itoa(int n, char s[]);

int main() {
  int n = -12345;
  char s[15];

  for (int i = 0; i < 10; i++) {
    s[i] = 0;
  }
  itoa(n, s);
  printf("%s\n", s);

  n = INT_MIN;

  itoa(n, s);
  // 无法处理最小值的情况
  printf("%s\n", s);
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
  int i, sign;
  if ((sign = n) < 0) {
    n = -n;
  }
  i = 0;
  /* generate digits in reverse order */
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}