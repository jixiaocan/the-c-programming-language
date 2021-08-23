#include <stdio.h>
#include <stdlib.h> /* for atof() */

#define MAXOP 100   // max size of operand or operator
#define NUMBER '0'  //标识找到一个数

int getop(char[]);
void push(double);
double pop(void);
void clear(void);

// 扩展4_3,增加栈操作
/* reverse Polish calculator */
int main() {
  int type;
  double op1, op2;
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
      case '?':  // 打印栈顶元素
        op2 = pop();
        printf("\t%.8g\n", op2);
        push(op2);
        break;
      case 'c':  // 清空栈
        clear();
        break;
      case 'd':  // 复制栈顶元素
        op2 = pop();
        push(op2);
        push(op2);
        break;
      case 's':  //交换栈顶两个元素的值
        op1 = pop();
        op2 = pop();
        push(op1);
        push(op2);
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

// clear the stack
void clear(void) { sp = 0; }

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
