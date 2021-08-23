
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>

#define MAXOP 100   // max size of operand or operator
#define NUMBER '0'  //标识找到一个数

int getop(char[]);
void ungets(char[]);
void push(double);
double pop(void);

// 参考4_3，修改main方法，命令行输入逆波兰表达式
// 注意，传入的*需要括号 ./a.out 2 3 5 '*' +
/* reverse Polish calculator */
int main(int argc, char *argv[]) {
  int type;
  double op2;
  char s[MAXOP];

  while (--argc > 0) {
    ungets(" ");      // push end of argument
    ungets(*++argv);  // push an argument
    switch (getop(s)) {
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
      default:
        printf("error: unknow command %s\n", s);
        break;
    }
  }
  printf("\t%.8g\n", pop());
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
int getop(char s[]) {
  int i, c;
  // 跳过空格与制表符
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.') return c;  // not a number
  i = 0;
  // collect integer part
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  // collect fraction part
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
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

void ungets(char s[]) {
  printf("push %s.\n", s);
  int len = strlen(s);
  while (len > 0) ungetch(s[--len]);
}
