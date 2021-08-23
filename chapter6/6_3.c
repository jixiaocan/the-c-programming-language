#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "getword.c"

#define MAXWORD 100
struct key {
  char *word;
  int count;
} keytab[] = {{"auto", 0},  {"break", 0},    {"case", 0},    {"char", 0},
              {"const", 0}, {"continue", 0}, {"default", 0}, {"unsigned", 0},
              {"void", 0},  {"volatile", 0}, {"while", 0}};

int getword(char *, int);
int binsearch(char *, struct key *, int);

#define NKEYS (sizeof keytab / sizeof(keytab[0]))

// 统计输入中C语言关键字的出现次数
int main() {
  int n;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) {
      if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
        printf("%s is at %d\n", word, n);
        keytab[n].count++;
      }
    }
  }
  for (n = 0; n < NKEYS; n++) {
    if (keytab[n].count > 0)
      printf("%4d %s\n", keytab[n].count, keytab[n].word);
  }
  return 0;
}

/* binsearch: 在 tab[0]到tab[n-1]中查找单词 */
int binsearch(char *word, struct key tab[], int n) {
  int cond;
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low + high) / 2;
    cond = strcmp(word, tab[mid].word);
    printf("mid = %d, tabword=%s, cond=%d\n", mid, tab[mid].word, cond);
    if (cond < 0) {
      high = mid - 1;
    } else if (cond > 0) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return -1;
}