#include <stdio.h>

// 这篇文章比较容易理解 https://www.runoob.com/w3cnote/quick-sort.html
/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
  int i, last;
  void swap(int v[], int i, int j);

  // do nothing if array contains fewer than two elements
  if (left >= right) {
    return;
  }
  // 使用中间的元素划分子集
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (v[i] < v[left]) swap(v, ++last, i);
  }
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
  int temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int main(){
    
}