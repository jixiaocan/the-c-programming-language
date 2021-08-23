#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h>

#define MAXOP 100   // max size of operand or operator
#define NUMBER '0'  //标识找到一个数

int getop(char[]);
void push(double);
double pop(void);

// 扩展 4_3，支持 % 运算，支持负数（主要修改 main 和 getop）
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
        // support modulus operator
      case '%':
        op2 = pop();
        if (op2 != 0.0) {
          push(fmod(pop(), op2));
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

int getch(void);
void ungetch(int);

// getop: get next character or numeric operand
// 支持解析负数
int getop(char s[]) {
  int i, c;
  // 跳过空格与制表符
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-') return c;  // not a number
  i = 0;
  // 判断是负号还是减号
  if (c == '-') {
    if (isdigit(c = getch()) || c == '.')
      s[++i] = c;  // negative number
    else {
      if (c != EOF) ungetch(c);
      return '-';  // minus sign
    }
  }

  // collect integer part
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  // collect fraction part
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  // 最后负数的负号哪来的？？？
  s[i] = '\0';
  if (c != EOF) ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

// buffer for ungetch
char buf[BUFSIZE];
// net free position in buf
int bufp = 0;

// get a (possibly pushed-back) character
int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
