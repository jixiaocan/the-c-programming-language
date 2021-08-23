#include <stdio.h>

#define BUFSIZE 100
// buffer for ungetch
static char buf[BUFSIZE];
// net free position in buf
static int bufp = 0;

// get a (possibly pushed-back) character
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
