#include <stdio.h>
#include <string.h>
#include "getinputline.c"
#define MAXLINE 1000

// 参考4_1
/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[]){
  char line[MAXLINE];
  int found = 0;
  while (getinputline(line, MAXLINE) > 0) {
    if (strstr(line, argv[1]) != NULL) {
      printf("%s", line);
      found++;
    }
  }
  return found;
}
