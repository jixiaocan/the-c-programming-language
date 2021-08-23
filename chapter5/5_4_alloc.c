#define ALLOCSIZE 10000  // 可用空间大小

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

/* return pointer to n characters */
char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    // 有足够的空间空间
    allocp += n;
    return allocp - n;
  } else {
    // 空间不足
    return 0;
  }
}
// 释放p指向的存储区
void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE) {
    allocp = p;
  }
}