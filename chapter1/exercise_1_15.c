#include <stdio.h>
float celsius(float fahr);
int main() {
  float fahr;
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
    printf("%3.0f %6.1f\n", fahr, celsius(fahr));
    fahr += step;
  }
}
// clesius: convert fahr into celsius
float celsius(float fahr) { return (5.0 / 9.0) * (fahr - 32.0); }