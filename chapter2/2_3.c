#include <stdio.h>

int main() {
  printf("%d\n", 037);
  printf("%d\n", 0x1f);

  enum escapes {
    BELL = '\a',
    BACKSPACE = '\b',
    TAB = '\t',
    NEWLINE = '\n',
    VTAB = '\v',
    RETURN = '\r'
  };

  enum boolean { NO, YES };

  enum months {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
  };

  enum months m;
  m = JAN;
  printf("%d", m);
}
