#include <stdio.h>

#define MAXHIST 15 /* max length of histogram */
#define MAXWORD 11 /* max length of a word */
#define IN 1       /* inside a word */
#define OUT 0      /* ouside a word */

// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the histogram with the bars horizontal; a
// vertical orientation is more challenging.
// 计算输入的单词长度，绘制水平直方图
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
  for (i = 0; i < MAXWORD; i++) {
    printf("%5d ~ %5d : ", i, wl[i]);
    if (wl[i] > 0) {
      if ((len = wl[i] * MAXHIST / maxvalue) <= 0) {
        len = 1;
      }
    } else {
      len = 0;
    }
    while (len > 0) {
      putchar('*');
      --len;
    }
    putchar('\n');
  }
  if (ovflow > 0) printf("There are %d words >= %d\n", ovflow, MAXWORD);
}