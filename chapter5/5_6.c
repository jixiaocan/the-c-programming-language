#include <stdio.h>
#include <string.h>

#include "5_4_alloc.c"
#include "getinputline.c"

#define MAXLINES 5000
char *lineptr[MAXLINES];  //  指向文本行的指针数组

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

// 对输入的文本行进行排序
int main() {
  int nlines;  // 读取的输入行数目

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
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



void qsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  // do nothing if array contains fewer than two elements
  if (left >= right) {
    return;
  }
  // 使用中间的元素划分子集
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (strcmp(v[i], v[left]) < 0) swap(v, ++last, i);
  }
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}