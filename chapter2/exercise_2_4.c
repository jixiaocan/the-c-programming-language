#include <stdio.h>

void squeeze(char s1[], char s2[]);

// Exercise 2-4. Write an alternative version of squeeze(s1,s2) that deletes
// each character in s1 that matches any character in the string s2.
int main() {
  char s1[] = "xiaocan";
  char s2[] = "an";
  squeeze(s1, s2);
  printf("%s\n", s1);
}

// delete each char in s1 which is in s2
void squeeze(char s1[], char s2[]) {
  int i, j, k;
  for (i = k = 0; s1[i] != '\0'; i++) {
    for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
      ;
    if (s2[j] == '\0') {
      s1[k++] = s1[i];
    }
  }
  s1[k] = '\0';
}