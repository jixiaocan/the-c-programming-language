#include <stdio.h>
// 返回字符串s的长度
int strlen2(char *s) {
  int n;
  for (n = 0; *s != '\0'; s++) {
    n++;
  }
  return n;
}

int main(){
    printf("hello world's length = %d\n", strlen2("hello world"));
}