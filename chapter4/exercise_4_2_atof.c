#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1000

// 简单计算器程序
int main() {
  double result, atof(char[]);
  char line[MAXLINE];
  int getinputline(char line[], int max);

  while (getinputline(line, MAXLINE) > 0) {
    printf("\t%g\n", result = atof(line));
  }
  return 0;
}
// 把字符串s转换为相应的双精度浮点数，支持科学计数法
double atof(char s[]) {
  double val, power;
  int i, sign;

  for (i = 0; isspace(s[i]); i++)  // 跳过空白符
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') i++; /* skip sign */
  for (val = 0.0; isdigit(s[i]); ++i) {
    val = 10.0 * val + (s[i] - '0');
  }
  if (s[i] == '.') {
    i++;
  }
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }

  val = sign * val / power;

  // 支持科学计数法，转换后面的e及指数
  int exp;
  if (s[i] == 'e' || s[i] == 'E') {
    sign = (s[++i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
      i++;
    }
    for (exp = 0; isdigit(s[i]); i++) {
      exp = 10 * exp + (s[i] - '0');
    }
    if (sign == 1) {
      // positive exponent
      while (exp-- > 0) {
        val *= 10;
      }
    } else {
      // negative exponent
      while (exp-- > 0) {
        val /= 10;
      }
    }
  }
  return val;
}

/* atoi: convert string s to integer using atof */
int atoi(char s[]) {
  double atof(char s[]);
  return (int)atof(s);
}

// getinputline: read a line into s, return length
int getinputline(char s[], int lim) {
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') s[i++] = c;

  if (c == '\n') {
    s[i++] = c;
  }
  // 字符数组以\0结尾
  s[i] = '\0';
  return i;
}