
// 将x中从第p位开始的n个位求反，其余各位保持不变
unsigned invert(unsigned x, int p, int n) {
  // 与 000..011100..0000异或
  return x ^ (~(~0 << n) << (p + 1 - n));
}