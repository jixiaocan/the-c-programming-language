#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* ouside a word */

/* Exercise 1-12. Write a program that prints its input one word per line. */
int main() {
  int c, state;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      // finish the word
      if (state == IN) {
        printf("\n");
      }
      state = OUT;
    } else {
      state = IN;
      putchar(c);
    }
  }
}