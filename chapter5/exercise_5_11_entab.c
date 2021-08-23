#include <stdio.h>

#define TABLEN 8
// Exercise 1-21. Write a program entab that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing. Use the same
// tab stops as for detab. When either a tab or a single blank would suffice to
// reach a tab stop, which should be given preference?
// 把空格替换为tab
int main() {
  int c, nb, nt, pos;

  nb = 0;  // blanks necessary
  nt = 0;  // tabs necessary
  for (pos = 1; (c = getchar()) != EOF; ++pos) {
    if (c == ' ') {
      if (pos % TABLEN != 0) {
        ++nb;
      } else {
        nb = 0;  // reset blanks
        ++nt;    // one more tab
      }
    } else {
      // ouput tab(s)
      for (; nt > 0; --nt) {
        putchar('\t');
      }
      // 下一个字符是tab，需要特殊处理
      if (c == '\t')
        nb = 0;  // forget the blank(s)
      else       // output blank(s)
        for (; nb > 0; --nb) putchar(' ');
      putchar(c);
      if (c == '\n') {
        pos = 0;
      } else if (c == '\t') {
        pos = pos + (TABLEN - (pos - 1) % TABLEN) - 1;
      }
    }
  }
}