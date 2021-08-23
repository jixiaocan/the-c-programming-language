#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getinputline(char line[], int maxline);
void copy(char to[], char from[]);

// print the longest input line
int main() {
  int len;                // current line length
  int max;                // maximum length seen so far
  char line[MAXLINE];     // current input line
  char longest[MAXLINE];  // longest line saved here

  max = 0;
  while ((len = getinputline(line, MAXLINE)) > 0) {
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
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  // 字符数组以\0结尾
  s[i] = '\0';
  return i;
}

// copy: copy 'from' into 'to';
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') ++i;
}