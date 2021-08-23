#include <stdio.h>

#define TABLEN 8
// Write a program detab that replaces tabs in the input with the proper number
// of blanks to space to the next tab stop. Assume a fixed set of tab stops, say
// every n columns. Should n be a variable or a symbolic parameter?
// 把 tab 替换成空格
int main() {
  int c, nb, len;
  nb = 0;  // number of blanks necessary
  len = 0; // the length of current line
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      nb = TABLEN - len % TABLEN;
      while (nb > 0) {
        putchar(' ');
        ++len;
        --nb;
      }
    } else if (c == '\n') {
      len = 0;
      putchar('\n');
    } else {
      len++;
      putchar(c);
    }
  }
}