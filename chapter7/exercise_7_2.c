#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100  // max number of chars in one line
#define OCTLEN 6     // lenght of an octal value

// print arbitrary input in a sensible way
int main(int argc, char *argv[]) {
  int c, pos;
  int inc(int pos, int n);
  pos = 0;  // position in the line
  while ((c = getchar()) != EOF) {
    if (iscntrl(c) || c == ' ') {
      // non-graphic or blank
      pos = inc(pos, OCTLEN);
      printf(" \\%03O ", c);
      if (c == '\n') {
        pos = 0;
        putchar('\n');
      }
    } else {
      pos = inc(pos, 1);
      putchar(c);
    }
  }
  return 0;
}

// increment position counter for output
int inc(int pos, int n) {
  if (pos + n < MAXLINE) {
    return pos + n;
  } else {
    putchar('\n');
    return n;
  }
}