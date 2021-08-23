#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getinputline(char line[], int maxline);
void copy(char to[], char from[]);

// Exercise 1-16. Revise the main routine of the longest-line program(1_9) so it
// will correctly print the length of arbitrary long input lines, and as much as
// possible of the text.
// 打印任意长度的输入行的长度，并尽可能多地打印文本
int main() {
  int len;                // current line length
  int max;                // maximum length seen so far
  char line[MAXLINE];     // current input line
  char longest[MAXLINE];  // longest line saved here

  max = 0;
  while ((len = getinputline(line, MAXLINE)) > 0) {
    // 打印输入的每一行的长度
    printf("%d, %s", len, line);
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  // 打印最长的字符数组
  if (max > 0) printf("the longest line is: %s", longest);
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

// copy: copy 'from' into 'to';
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') ++i;
}