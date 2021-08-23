#include <stdio.h>

// 3_6先生成数组，然后再反向打印
// 使用递归打印十进制数n，注意，不能处理最大的负数
void printd(int n) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (n / 10) printd(n / 10);
  putchar(n %  10 + '0');
}
int main() {
    printd(-123);
    printf("\n");
    printd(23433);
}