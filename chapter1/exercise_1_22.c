#include <stdio.h>

#define MAXCOL 10
#define TABINC 8

char line[MAXCOL];  // input line

int exptab(int pos);
int findblank(int pos);
int newpos(int pos);
void printl(int post);

// fold long input lines into two or more shorter lines after the last
// non-blank character that occurs before the n-th column of input.
// 将长的输入行换行
int main() {
  int c, pos;
  pos = 0;  // position in the line
  while ((c = getchar()) != EOF) {
    line[pos] = c;  // store current character
    if (c == '\t') {
      pos = exptab(pos);
    } else if (c == '\n') {
      printl(pos);  // print current input line
      pos = 0;
    } else if (++pos >= MAXCOL) {
      pos = findblank(pos);
      printl(pos);
      pos = newpos(pos);
    }
  }
}
// print line until pos column
void printl(int pos) {
  for (int i = 0; i < pos; i++) {
    putchar(line[i]);
  }
  if (pos > 0) {  // any chars printed?
    putchar('\n');
  }
}

// expand tab into blanks
int exptab(int pos) {
  line[pos] = ' ';  // tab is at least one blank
  for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos) line[pos] = ' ';
  if (pos < MAXCOL) {  // room left in current line
    return pos;

  } else {  // current line is full
    printl(pos);
    return 0;  // reset current position
  }
}

// find blank's position
int findblank(int pos) {
  while (pos > 0 && line[pos] != ' ') {
    --pos;
  }
  if (pos == 0)  // no blanks in the line ?
    return MAXCOL;
  else               // at least one blank
    return pos + 1;  // position after the blank
}

int newpos(int pos) {
  int i, j;
  if (pos <= 0 || pos >= MAXCOL) {
    return 0;  // nothing to rearrange
  } else {
    i = 0;
    for (j = pos; j < MAXCOL; ++j) {
      line[i] = line[j];
      ++i;
    }
    return i;  // new position in line
  }
}