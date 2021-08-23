#include <stdio.h>

#define MAXHIST 15 /* max length of histogram */
#define MAXWORD 11 /* max length of a word */
#define IN 1       /* inside a word */
#define OUT 0      /* ouside a word */

// 计算输入的单词长度，绘制垂直直方图
int main() {
  int c, state, i, nc;
  int len;          // length of each bar
  int maxvalue;     // maximum value for wl[]
  int ovflow;       // number of overflow words
  int wl[MAXWORD];  // word length counters

  state = OUT;
  nc = 0;      // number of char in a word
  ovflow = 0;  // number of words >= MAXWORD

  for (i = 0; i < MAXWORD; i++) {
    wl[i] = 0;
  }

  // 计算输入每个单词的长度
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      state = OUT;
      if (nc > 0) {
        if (nc < MAXWORD) {
          ++wl[nc];
        } else {
          ++ovflow;
        }
      }
      nc = 0;
    } else if (state == OUT) {
      state = IN;
      nc = 1;  // beginning of a new word
    } else {
      ++nc;  // inside a word
    }
  }
  // 查找最大长度
  maxvalue = 0;
  for (i = 0; i < MAXWORD; i++) {
    if (wl[i] > maxvalue) {
      maxvalue = wl[i];
    }
  }

  // 绘制直方图
  for (i = MAXHIST; i > 0; i--) {
    for (int j = 1; j < MAXWORD; j++) {
      if (wl[j] * MAXHIST / maxvalue >= i) {
        printf("%4s ", "*");
      } else {
        printf("%4s ", " ");
      }
    }
    putchar('\n');
  }

  for (i = 1; i < MAXWORD; i++) {
    printf("%4d ", i);
  }
  putchar('\n');
  for (i = 1; i < MAXWORD; i++) {
    printf("%4d ", wl[i]);
  }
  putchar('\n');
  if (ovflow > 0) printf("There are %d words >= %d\n", ovflow, MAXWORD);
}