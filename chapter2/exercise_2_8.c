#include <stdio.h>

int wordlength(void);
unsigned rightrot(unsigned x, int n);
int main() { printf("word length = %d\n", wordlength()); }
// 将x循环右移n位（从最右端移出的位将从最左端移入）
unsigned rightrot(unsigned x, int n) {
  unsigned rbits;

  if ((n = n % wordlength()) > 0) {
    rbits = ~(~0 << n) & x;               // n rightmost bits of x
    rbits = rbits << (wordlength() - n);  // n rightmost bits to left
    x = x >> n;                           // x shifted n positions right
    x = x | rbits;
  }
  return x;
}

// computes word length of the machine
int wordlength(void) {
  int i;
  unsigned v = (unsigned)~0;

  for (i = 1; (v = v >> 1) > 0; i++)
    ;
  return i;
}