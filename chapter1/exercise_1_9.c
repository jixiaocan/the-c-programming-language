#include <stdio.h>

#define NONBLANK 'a'
#define BLANK ' '

// Exercise 1-9. Write a program to copy its input to its output, replacing each
// string of one or more blanks by a single blank.
int main() {
  int c, lastc;
  lastc = NONBLANK;  // last input char
  while ((c = getchar()) != EOF) {
    if (c != BLANK) {
      putchar(c);
    } else if (lastc != BLANK) {
      putchar(c);
    }
    lastc = c;
  }
}