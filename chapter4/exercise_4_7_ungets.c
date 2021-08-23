#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int main() {}

// buffer for ungetch
char buf[BUFSIZE];
// net free position in buf
int bufp = 0;

// get a (possibly pushed-back) character
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

// Write a routine ungets(s) that will push back an entire string onto the
// input.
void ungets(char s[]) {
  int len = strlen(s);
  while (len > 0) ungetch(s[--len]);
}