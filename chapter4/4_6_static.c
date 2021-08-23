#include <stdio.h>

int add(int opt, int opt2) {
  static int result = 0;
  if (result != 0) {
    printf("last result is %d\n", result);
  }
  result = opt + opt2;
  return result;
}
int main() {
  add(1, 2);
  add(2, 3);
  add(3, 3);
}