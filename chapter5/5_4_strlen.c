#include <stdio.h>
// 返回字符串s的长度
int strlen2(char *s) {
  char *p = s;
  while (*p != '\0') {
    p++;
  }
  return p - s;
}

int main() { printf("hello world's length = %d\n", strlen2("hello world")); }