#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define LONGLINE 80

int getinputline(char line[], int maxline);
int removeblank(char s[]);

// Exercise 1-18. Write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.
// 删除每个输入行末尾的空格及制表符，并删除空行
int main() {
  char line[MAXLINE];  // current input line

  while (getinputline(line, MAXLINE) > 0) {
    if (removeblank(line) > 0) printf("%s", line);
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

// remove trailing blanks and tabs from character string s
int removeblank(char s[]) {
  int i;
  i = 0;
  while (s[i] != '\n') ++i;
  --i;  // back off from \n
  while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
    --i;
  }
  if (i >= 0) {  // is it a nonblank line?
    ++i;
    s[i] = '\n';
    ++i;
    s[i] = '\0';
  }
  return i;
}