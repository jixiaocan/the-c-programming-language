#include <stdio.h>

// getinputline: read a line into s, return length
int getinputline(char *s, int lim) {
  int c;
  char *t = s;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') *s++ = c;

  if (c == '\n') {
    *s++ = c;
  }
  // 字符数组以\0结尾
  *s = '\0';
  return s - t;
}

// 参考3_5
/* atoi: convert s to integer; pointer version */
int atoi(char *s) {
  int i, n, sign;

  for (i = 0; isspace(*s); s++) /* skip white space */
    ;
  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-') s++; /* skip sign */
  for (n = 0; isdigit(*s); ++s) {
    n = 10 * n + (*s - '0');
  }
  return sign * n;
}

// 参考3_6
/* itoa: convert n to characters in s */
void itoa(int n, char *s) {
  int sign;
  char *t = s;

  if ((sign = n) < 0) {
    n = -n;
  }

  /* generate digits in reverse order */
  do {
    *s++ = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) {
    *s++ = '-';
  }
  *s = '\0';
  reverse(t);
}

// 参考3_5
// 倒置字符串s中各个字符的位置
void reverse(char *s) {
  int c;
  char *t;
  for (t = s + (strlen(s) - 1); s < t; s++, t--) {
    // 交换
    c = *s;
    *s = *t;
    ;
    *t = c;
  }
}

// 参考4_1
/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t) {
  char *b = s;
  char *p, *r;
  for (; *s != '\0'; s++) {
    for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
      ;
    if (r > t && *r == '\0') return s - b;
  }
  return -1;
}

#define NUMBER '0'
// getop: get next character or numeric operand
int getop(char *s) {
  int c;
  // 跳过空格与制表符
  while ((*s = c = getch()) == ' ' || c == '\t')
    ;
  *(s+1) = '\0';
  if (!isdigit(c) && c != '.') return c;  // not a number
  
  // collect integer part
  if (isdigit(c))
    while (isdigit(*++s = c = getch()))
      ;
  // collect fraction part
  if (c == '.')
    while (isdigit(*++s = c = getch()))
      ;
  *s = '\0';
  if (c != EOF) ungetch(c);
  return NUMBER;
}