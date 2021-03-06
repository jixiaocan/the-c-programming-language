#include <stdio.h>

int main() {}

// 最多只压回一个字符
char buf = 0;

// get a (possibly pushed-back) character
int getch(void) {
  int c;
  if (buf != 0)
    c = buf;
  else
    c = getchar();
  buf = 0;
  return c;
}

void ungetch(int c) {
  if (buf != 0)
    printf("ungetch: too many characters\n");
  else
    buf = c;
}