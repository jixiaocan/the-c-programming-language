#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
int main() { printf("%d\n", getbits(12345, 3, 3)); }

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
  return (x >> (p + 1 - n)) & ~(~0 << n);
}