#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int main() {}

// 把char数组改成 int数组，就可以正确处理压回的EOF
// buffer for ungetch
int buf[BUFSIZE];
// net free position in buf
int bufp = 0;

// get a (possibly pushed-back) character
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

// push character back onto the input
void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
