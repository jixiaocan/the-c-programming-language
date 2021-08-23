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
struct key *binsearch(char *, struct key *, int);

#define NKEYS (sizeof keytab / sizeof(keytab[0]))

// 使用结构指针重写6_3的程序
// 统计输入中C语言关键字的出现次数
int main() {
  char word[MAXWORD];
  struct key *p;

  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) {
      if ((p = binsearch(word, keytab, NKEYS)) != NULL) {
        p->count++;
      }
    }
  }
  for (p = keytab; p < keytab + NKEYS; p++) {
    if (p->count > 0) {
      printf("%4d %s\n", p->count, p->word);
    }
  }

  return 0;
}

/* binsearch: 在 tab[0]到tab[n-1]中查找单词 */
struct key *binsearch(char *word, struct key *tab, int n) {
  int cond;
  struct key *low = &tab[0];
  struct key *high = &tab[n];
  struct key *mid;

  while (low < high) {
    mid = low + (high - low) / 2;
    cond = strcmp(word, mid->word);
    printf("tabword=%s, cond=%d\n", mid->word, cond);
    if (cond < 0) {
      high = mid;
    } else if (cond > 0) {
      low = mid + 1;
    } else {
      return mid;
    }
  }
  return NULL;
}