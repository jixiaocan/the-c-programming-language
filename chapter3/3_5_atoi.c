#include <stdio.h>
#include <ctype.h>
// 2_7曾经写过一个简单的版本
// 可以处理前面的空白符以及加减号
// 标准库提供了一个更完善的函数 strtol，将字符串转成长整型数
int atoi(char s[]);

int main() {
  char s[] = "12345";
  printf("%s convert to integer is %d\n", s, atoi(s));
  char t[] = "  -2334";
  printf("%s convert to integer is %d\n", t, atoi(t));
}
/* atoi: convert s to integer; version 2 */
int atoi(char s[]) {
  int i, n, sign;

  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') i++; /* skip sign */
  for (n = 0; isdigit(s[i]); ++i) {
    n = 10 * n + (s[i] - '0');
  }
  return sign * n;
}