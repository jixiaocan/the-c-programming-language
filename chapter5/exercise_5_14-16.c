#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "5_4_alloc.c"
#include "getinputline.c"

#define MAXLINES 5000 /* max #lines to be sorted */

#define NUMERIC 1
#define DECR 2
#define FOLD 4  // fold upper and lower cases
#define DIR 8   // directory order

int charcmp(char *, char *);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int decr);
void qsort2(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);

static char option = 0;

// 参考5_11
/* sort input lines */
int main(int argc, char *argv[]) {
  char *lineptr[MAXLINES]; /* pointers to text lines */
  int nlines;              /* number of input lines read */
  int c, rc = 0;

  while (--argc > 0 && (*++argv)[0] == '-') {
    while ((c = *++argv[0]) != '\0') {
      switch (c) {
        case 'n':
          option |= NUMERIC;
          break;
        case 'r':
          option |= DECR;
          break;
        case 'f':
          option |= FOLD;
          break;
        case 'd':
          option |= DIR;
          break;
        default:
          printf("sort: illegal option %c\n", c);
          argc = 1;
          rc = -1;
          break;
      }
    }
  }
  if (argc) {
    printf("Usage: sort -dfnr \n");
  } else {
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
      if (option & NUMERIC)
        qsort2((void **)lineptr, 0, nlines - 1,
               (int (*)(void *, void *))numcmp);
      else if (option & FOLD)
        qsort2((void **)lineptr, 0, nlines - 1,
               (int (*)(void *, void *))charcmp);
      else
        qsort2((void **)lineptr, 0, nlines - 1,
               (int (*)(void *, void *))strcmp);
      writelines(lineptr, nlines, option & DECR);
    } else {
      printf("input too big to sort\n");
      rc = -1;
    }
  }
  return rc;
}

int charcmp(char *s, char *t) {
  char a, b;
  int fold = (option & FOLD) ? 1 : 0;
  int dir = (option & DIR) ? 1 : 0;
  do {
    if (dir) {
      while (!isalnum(*s) && *s != ' ' && *s != '\0') s++;
      while (!isalnum(*t) && *t != ' ' && *t != '\0') t++;
    }
    a = fold ? tolower(*s) : *s;
    s++;
    b = fold ? tolower(*t) : *t;
    t++;
    if (a == b && a == '\0') return 0;
  } while (a == b);

  return a - b;
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
void writelines(char *lineptr[], int nlines, int decr) {
  int i;
  if (decr) {
    for (i = nlines - 1; i >= 0; i--) {
      printf("%s\n", lineptr[i]);
    }
  } else
    for (i = 0; i < nlines; i++) {
      printf("%s\n", lineptr[i]);
    }
}

void writelines2(char *lineptr[], int nlines) {
  while (nlines-- > 0) printf("%s\n", *lineptr++);
}
