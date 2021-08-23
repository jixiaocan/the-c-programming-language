#include <ctype.h>
#include <stdio.h>

#include "getch.c"

int getint(int *pn) {
  int c, sign;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '-' || c == '+') c = getchar();

  for (*pn = 0; isdigit(c); c = getch()) {
    *pn = *pn * 10 + (c - '0');
  }
  *pn *= sign;
  if (c != EOF) ungetch(c);
  return c;
}

int main(){
    int pn = 0;
    int result = getint(&pn);
    printf("%d\n", pn);
}