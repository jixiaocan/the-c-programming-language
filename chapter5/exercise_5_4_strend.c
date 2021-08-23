#include <stdio.h>

// return 1 if string t occurs at the end of s
int strend(char *s, char *t) {
  char *bs = s;  // remember beginning of strs
  char *bt = t;
  for (; *s; s++)  // end of the string s
    ;
  for (; *t; t++)  // end of the string t;
    ;

  for (; *s == *t; s--, t--)
    if (t == bt || s == bs) break;
  if (*s == *t && t == bt && *s != '\0')
    return 1;
  else {
    return 0;
  }
}

int main() {
  char *s = "hello world";
  char *t = "world2";
  printf("%d\n", strend(s, t));
}