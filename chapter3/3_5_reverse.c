#include <string.h>

// 倒置字符串s中各个字符的位置
void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    // 交换
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}