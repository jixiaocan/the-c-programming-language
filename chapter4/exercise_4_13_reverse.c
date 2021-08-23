#include <stdio.h>
#include <string.h>
void reverse(char s[]);

int main() {
  char s[] = "hello world!";
  reverse(s);
  printf("%s\n", s);
}
// Write a recursive version of the function reverse(s), which reverses the
// string s in place. 倒置字符串s中各个字符的位置
void reverse(char s[]) {
  void reverser(char s[], int i, int len);

  reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len) {
  int c, j;
  j = len - (i + 1);
  if (i < j) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
    reverser(s, ++i, len);
  }
}
