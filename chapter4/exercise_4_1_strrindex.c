#include <string.h>

/* strrindex: return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[]) {
  int i, j, k, pos;
  pos = -1;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') pos = i;
  }
  return pos;
}

// 第二种方法，直接从右边开始查找
int strrindex(char s[], char t[]) {
  int i, j, k;
  for (i = strlen(s) - strlen(t); i >= 0; i--) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') return i;
  }
  return -1;
}