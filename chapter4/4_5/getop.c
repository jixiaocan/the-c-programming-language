#include <stdio.h>
#include <ctype.h>
#include "calc.h"

// getop: get next character or numeric operand
int getop(char s[]) {
  int i, c;
  static int last;
  // 跳过空格与制表符
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') return c;  // not a number
  i = 0;
  // collect integer part
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  // collect fraction part
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if (c != EOF) ungetch(c);
  return NUMBER;
}