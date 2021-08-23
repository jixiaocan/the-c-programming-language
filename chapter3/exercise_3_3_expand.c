#include <stdio.h>

int main() {
  
}

// Write a function expand(s1,s2) that expands shorthand notations like a-z in
// the string s1 into the equivalent complete list abc...xyz in s2.
void expand(char s1[], char s2[]) {
  char c;
  int i, j;

  while ((c = s1[i++]) != '\0') {
    if (s1[i] == '-' && s1[i + 1] >= c) {
      i++;
      while (c < s1[i]) s2[j++] = c++;
    } else {
      s2[j++] = c;
    }
  }
  s2[j] = '\0';
}