#include <unistd.h>
#include <stdio.h>

#define BUFSIZE 1024

// 将输入复制到输出
int main() {
  char buf[BUFSIZE];
  int n;

  while ((n = read(0, buf, BUFSIZE)) > 0) write(1, buf, n);
  return 0;
}

// 无缓冲的单字符输入
int getchar(void) {
  char c;
  return (read(0, &c, 1) == 1) ? (unsigned char)c : EOF;
}

// 简单的带缓冲区的版本
int getchar2(void) {
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;
    if(n == 0){
        n = read(0, buf, sizeof buf);
        bufp = bufp;
    }
  return (--n >=0) ? (unsigned char)*bufp++ : EOF;
}