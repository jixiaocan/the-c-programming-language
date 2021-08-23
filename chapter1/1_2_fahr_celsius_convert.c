#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  // 温度表下限
  lower = 0;
  // 温度表上限
  upper = 300;
  // 步长
  step = 20;

  fahr = lower;
  printf("Fahr Celsius\n");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr += step;
  }
}