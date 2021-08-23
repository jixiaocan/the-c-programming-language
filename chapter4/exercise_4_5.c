#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>

#define MAXOP 100   // max size of operand or operator
#define NUMBER '0'  // signal that a number was found
#define NAME 'n'    // signal that a name was found

int getop(char[]);
void push(double);
double pop(void);
void mathfun(char[]);  // 数学计算

// 扩展4_3，支持 sin、exp、pow 计算
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
      case NAME:
        mathfun(s);
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

// check string s for supported math functions
void mathfun(char s[]) {
  double op2;

  if (strcmp(s, "sin") == 0)
    push(sin(pop()));
  else if (strcmp(s, "cos") == 0)
    push(cos(pop()));
  else if (strcmp(s, "exp") == 0)
    push(exp(pop()));
  else if (strcmp(s, "pow") == 0) {
    op2 = pop();
    push(pow(pop(), op2));
  } else {
    printf("error, %s not supported\n", s);
  }
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

// 支持获取 math func
// getop: get next character or numeric operand, or math func
int getop(char s[]) {
  int i, c;
  // 跳过空格与制表符
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  i = 0;
  if (islower(c)) {
    while (islower(s[++i] = c = getch()))
      ;
    s[i] = '\0';
    if (c != EOF) ungetch(c);
    if (strlen(s) > 1)
      return NAME;
    else
      return c;
  }
  if (!isdigit(c) && c != '.') return c;  // not a number
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
