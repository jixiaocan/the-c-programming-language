#include <stdio.h>

// 逆序打印（从300度到0度的顺序）
int main() {
  int fahr;

  printf("Fahr Celsius\n");
  for (fahr = 300; fahr >= 0; fahr -= 20) {
    printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
  }
}