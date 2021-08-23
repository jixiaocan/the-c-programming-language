#include <stdio.h>

int bitcount(unsigned x);

int main() {
  unsigned x = 0x1f;
  int count = bitcount(x);
  printf("%x 有 %d 个 1\n", x, count);
}

/* bitcount: count 1 bits in x */
// exercise 2_9 is a faster version
int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x >>= 1)

    if (x & 01) b++;
  return b;
}