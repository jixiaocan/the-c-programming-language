#include <stdio.h>

#define NONBLANK 'a'
#define BLANK ' '

// Exercise 1-10. replace tabs and backspaces with visible characters.
int main() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if (c == '\b') {
      printf("\\b");
    } else if (c == '\\') {
      printf("\\\\");
    } else {
      putchar(c);
    }
  }
}