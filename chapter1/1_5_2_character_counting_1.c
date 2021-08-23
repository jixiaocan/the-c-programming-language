#include <stdio.h>

/* count characters in input; 1st version */
int main() {
  long nc;

  // 必须初始化，否则有问题
  nc = 0;
  while (getchar() != EOF) {
    ++nc;
  }
  printf("%ld\n", nc);
}