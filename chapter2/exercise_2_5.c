#include <stdio.h>

int any(char s1[], char s2[]);
// The standard library function strpbrk does the same job but returns a pointer
// to the location.)
int main() {
  char s1[] = "xiaocan";
  char s2[] = "an";
  int location = any(s1, s2);
  printf("%d\n", location);
}

// return first location in s1 where any char from s2 occurs
int any(char s1[], char s2[]) {
  int i, j, k;
  for (i = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0'; j++) {
      if (s2[j] == s1[i]) return i;
    }
  }
  return -1;
}