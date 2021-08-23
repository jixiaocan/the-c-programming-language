#include <stdio.h>
#include <string.h>

#include "5_4_alloc.c"
#include "getinputline.c"

#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

// 参考5_6
/* sort input lines */
int main(int argc, char *argv[]) {
  int nlines;      /* number of input lines read */
  int numeric = 0; /* 1 if numeric sort */

  // 判断比较字符串还是比较数值
  if (argc > 1 && strcmp(argv[1], "-n") == 0) numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort2((void **)lineptr, 0, nlines - 1,
           (int (*)(void *, void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}

/* qsort2: sort v[left]...v[right] into increasing order */
void qsort2(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;

  void swap(void *v[], int, int);

  if (left >= right) /* do nothing if array contains */
    return;          /* fewer than two elements */
  swap(v, left, (left + right) / 2);
  last = left;

  for (i = left + 1; i <= right; i++)
    // 使用函数指针
    if ((*comp)(v[i], v[left]) < 0) swap(v, ++last, i);
  swap(v, left, last);
  qsort2(v, left, last - 1, comp);
  qsort2(v, last + 1, right, comp);
}

#include <stdlib.h>

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

#define MAXLEN 1000  // 每个输入文本行的最大长度
int getinputline(char *, int);
char *alloc(int);

// 读取输入行
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while ((len = getinputline(line, MAXLEN)) > 0) {
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0';  // delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;  // 该数组中保存着指针
    }
  }
  return nlines;
}

// write output lines
void writelines(char *lineptr[], int nlines) {
  int i;
  for (i = 0; i < nlines; i++) {
    printf("%s\n", lineptr[i]);
  }
}

void writelines2(char *lineptr[], int nlines) {
  while (nlines-- > 0) printf("%s\n", *lineptr++);
}
