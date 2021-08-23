#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int max;                // maximum length seen so far
char line[MAXLINE];     // current input line
char longest[MAXLINE];  // longest line saved here

int getinputline(void);
void copy(void);

// 修改 1-9，使用外部变量
int main() {
  int len;  // current line length
  // declare extern variables, can omit
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getinputline()) > 0) {
    if (len > max) {
      max = len;
      copy();
    }
  }
  // 打印最长的字符数组
  if (max > 0) printf("the longest line is: %s", longest);
  return 0;
}

// getinputline: read a line into s, return length
int getinputline(void) {
  int c, i;
  extern char line[];
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    line[i] = c;
  }
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  // 字符数组以\0结尾
  line[i] = '\0';
  return i;
}

// copy: copy 'from' into 'to';
void copy(void) {
  int i;
  // extern char line[], longest[];
  i = 0;
  while ((longest[i] = line[i]) != '\0') ++i;
}