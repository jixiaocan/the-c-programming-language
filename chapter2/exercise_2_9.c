#include <stdio.h>

int bitcount(unsigned x);

int main() {
  unsigned x = 0x1f;
  int count = bitcount(x);
  printf("%x 有 %d 个 1\n", x, count);
}

/* bitcount: count 1 bits in x - faster version */
// x &= (x-1) deletes the rightmost 1-bit in x
int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x &= x - 1) ++b;
  return b;
}