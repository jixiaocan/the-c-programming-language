#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

// Write a function setbits(x,p,n,y) that returns x with the n bits that
// begin at position p set to the rightmost n bits of y, leaving the other
// bits unchanged.
int main() { printf("%x\n", setbits(0x1234, 5, 5, 0x24)); }

// set n bits of x at position p with bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  // xxx...xnnnx...xxx
  // yyy..........ynnn
  return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}