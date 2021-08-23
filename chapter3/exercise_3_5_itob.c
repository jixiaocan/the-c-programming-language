#include <stdio.h>

#include "3_5_reverse.c"
// Write the function itob(n,s,b) that converts the integer n into a base b
// character representation in the string s. In particular, itob(n,s,16) formats
// s as a hexadecimal integer in s.
void itob(int n, char s[], int b);
int main() {
  int n = -314156;
  char s[10];
  for (int i = 0; i < 10; i++) {
    s[i] = 0;
  }
  int b = 16;
  itob(n, s, b);
  printf("%s\n", s);
}
// convert n to characters in s ~ base b
void itob(int n, char s[], int b) {
  int i, j, sign;

  if ((sign = n) < 0) n = -n;
  i = 0;
  do {
    j = n % b;
    s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;
    n /= b;
  } while (n != 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}