#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */
int getinputline(char line[], int maxline);
int strindex(char s[], char t[]);

char pattern[] = "ould"; // 待查找的模式

int main() {
    char line[MAXLINE];
    int found = 0;
    while(getinputline(line, MAXLINE) > 0){
      if (strindex(line, pattern) >= 0) {
        printf("%s", line);
        found++;
      }
    }
    return found;
}

// 参考1_9
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

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
  int i, j, k;
  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') return i;
  }
  return -1;
}