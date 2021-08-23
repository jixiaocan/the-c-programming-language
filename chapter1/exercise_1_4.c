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

  celsius = lower;
  printf("Celsius Fahr\n");
  while (celsius <= upper) {
    fahr = celsius * 9.0 / 5.0 + 32.0;
    printf("%3.0f %6.1f\n", celsius, fahr);
    celsius += step;
  }
}