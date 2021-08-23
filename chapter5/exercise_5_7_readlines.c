#include <string.h>

#define MAXLEN 1000   // max length of line
#define MAXSTOR 5000  // size of available storage space

// Rewrite readlines to store lines in an array supplied by main, rather than
// calling alloc to maintain storage. How much faster is the program?
//  读取输入行
int readlines(char *lineptr[], char *linestor, int maxlines) {
  int len, nlines;
  char line[MAXLEN];
  char *p = linestor;
  char *linestop = linestor + MAXSTOR;

  nlines = 0;
  while ((len = getinputline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || p + len > linestop)
      return -1;
    else {
      line[len - 1] = '\0';  // delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;  // 该数组中保存着指针
      p += len;
    }
  }
  return nlines;
}
