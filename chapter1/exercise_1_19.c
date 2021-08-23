#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */
#define LONGLINE 80

int getinputline(char line[], int maxline);
void reverse(char s[]);

// Exercise 1-19. Write a function reverse(s) that reverses the character string
// s. Use it to write a program that reverses its input a line at a time.
int main() {
  char line[MAXLINE];  // current input line

  while (getinputline(line, MAXLINE) > 0) {
    reverse(line);
    printf("%s", line);
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

void reverse(char s[]) {
  int i, j;
  i = 0;
  // find the end of string s
  while (s[i] != '\0') ++i;
  --i;  // back off from \0

  // leave newline in place
  if (s[i] == '\n') --i;
  int temp;
  for (j = 0; j < i; j++, i--) {
    // swap s[i] and s[j]
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}
