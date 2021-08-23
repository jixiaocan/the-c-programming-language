#include <ctype.h>
#include <stdio.h>

#include "getch.c"

int getint(int *pn) {
  int c, d, sign;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '-' || c == '+') {
    d = c;
    if(!isdigit(c = getch())){
      if(c !=EOF)
        ungetch(c);
      ungetch(d);
      return d;
    }
  }

  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = *pn * 10 + (c - '0');
  }
  *pn *= sign;
  if (c != EOF) ungetch(c);
  return c;
}

int main() {
  int pn = 0;
  int result = getint(&pn);
  printf("pn = %d\n", pn);
  printf("result = %c\n", result);
}