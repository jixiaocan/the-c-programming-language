#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100   // max size of operand or operator
#define NUMBER '0'  //标识找到一个数
#define MAXLINE 100

int getop(char[]);
void push(double);
double pop(void);

// 扩展4_3，使用getinputline代替getch与ungetch获取操作数
/* reverse Polish calculator */
int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':  // 左右两个操作数必须区分
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0) {
          push(pop() / op2);
        } else {
          printf("error: zero divisor\n");
        }
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknow command %s\n", s);
        break;
    }
  }
  return 0;
}

#define MAXVAL 100  // maximum depth of val stack
// 定义栈共享的外部变量
int sp = 0;          // next free stack position
double val[MAXVAL];  // value stack

/* push: push f onto value stack */
void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getinputline(char line[], int limit);

int li = 0;          // input line index
char line[MAXLINE];  // one input line

// getop: get next character or numeric operand
int getop(char s[]) {
  int i, c;
  if (line[li] == '\0') {
    if (getinputline(line, MAXLINE) == 0) {
      return EOF;
    } else {
      li = 0;
    }
  }

  // 使用getch的地方，都从lineu数组获取
  // 跳过空格与制表符
  while ((s[0] = c = line[li++]) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') return c;  // not a number
  i = 0;
  // collect integer part
  if (isdigit(c))
    while (isdigit(s[++i] = c = line[li++]))
      ;
  // collect fraction part
  if (c == '.')
    while (isdigit(s[++i] = c = line[li++]))
      ;
  s[i] = '\0';
  li--;
  return NUMBER;
}

// getinputline: read a line into s, return length
int getinputline(char s[], int lim) {
  int c, i;
  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') s[i++] = c;

  if (c == '\n') {
    s[i++] = c;
  }
  // 字符数组以\0结尾
  s[i] = '\0';
  return i;
}
