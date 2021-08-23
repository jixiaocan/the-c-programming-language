#include <ctype.h>
#include <stdio.h>

#include "getch.c"

// 可以参考4_2，把字符串转成浮点数
int getfloat(float *pn) {
  int c, sign;
  double power;

  while (isspace(c = getch()))
    ;

  if (!isdigit(c) && c != EOF && c != '-' && c != '+' && c != '.') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '-' || c == '+') {
    c= getch();
  }
  // 获取整数部分
  for (*pn = 0.0; isdigit(c); c = getch()) {
    *pn = *pn * 10.0 + (c - '0');
  }
  if (c == '.') {
    c = getch();
  }
  // 获取小数部分
  for (power = 1.0; isdigit(c); c = getch()) {
    *pn = 10.0 * *pn + (c - '0');
    power *= 10.0;
  }

  *pn = sign * *pn / power;
  if (c != EOF) ungetch(c);
  return c;
}

int main() {
  float pn = 0.0;
  int result = getfloat(&pn);
  printf("pn = %f\n", pn);
  printf("result = %c\n", result);
}