#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define LONGLINE 80

int getinputline(char line[], int maxline);

// Exercise 1-17. Write a program to print all input lines that are longer than
// 80 characters.
// 打印长度大于80个字符的所有输入行
int main() {
  int len;             // current line length
  char line[MAXLINE];  // current input line

  while ((len = getinputline(line, MAXLINE)) > 0) {
    if (len > LONGLINE) printf("%s", line);
  }
  return 0;
}

// getinputline: read a line into s, return length
int getinputline(char s[], int lim) {
  // 仍然使用 i 计算长度，使用 j 维护可存储的长度
  int c, i, j;
  j = 0;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 2) {
      s[j] = c;  // line still in boundaries
      ++j;
    }
  }
  if (c == '\n') {
    s[j] = c;
    ++j;
    ++i;
  }
  // 字符数组以\0结尾
  s[j] = '\0';
  return i;
}