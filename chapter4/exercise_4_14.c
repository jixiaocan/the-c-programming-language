#include <stdio.h>
// Define a macro swap(t,x,y) that interchanges two arguments of type t.
#define swap(t, x, y) \
  {                   \
    t _z;             \
    _z = y;           \
    y = x;            \
    x = _z;           \
  }

// 注意，传入的变量名称不能是 _z

int main() {
  int x = 5;
  int y = 6;
  swap(int, x, y);
  printf("x = %d\n", x);
  printf("y = %d\n", y);
}