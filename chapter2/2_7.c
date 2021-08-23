#include <stdio.h>

int atoi(char s[]);
int lower(int c);

int main() {
  char s[] = "12345";
  printf("%s convert to integer is %d\n", s, atoi(s));
  printf("%c to lower is %c\n", 'B', lower('B'));
}
// convert s to integer
int atoi(char s[]) {
  int i, n;
  n = 0;
  for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) {
    n = 10 * n + (s[i] - '0');
  }
  return n;
}

// convert c to lower case; ASCII only
int lower(int c) {
  if (c >= 'A' && c <= 'Z') {
    return c + 'a' - 'A';
  } else {
    return c;
  }
}