#include <stdio.h>
#include <stdlib.h>

// convert n to characters in s , recursive
void itoa(int n, char s[]) {
  static int i;

  if (n / 10)
    itoa(n / 10, s);
  else {
    i = 0;
    if (n < 0) s[i++] = '-';
  }
  s[i++] = abs(n) % 10 + '0';
  s[i] = '\0';
}

int main(){
    char s[10];
    int n = -123234;
    for(int i =0; i < 10; i++){
        s[i]= '0';
    }
    itoa(n, s);
    printf("%s\n", s);
    n = 32344;
    itoa(n, s);
    printf("%s\n", s);
}