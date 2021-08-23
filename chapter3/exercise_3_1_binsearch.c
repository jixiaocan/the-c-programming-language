#include <stdio.h>

// Write a version with only one test inside the loop
// and measure the difference in run-time.
/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  mid = (low + high) / 2;
  while (low <= high && v[mid] != x) {
    if (x < v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (low + high) / 2;
  }
  if (v[mid] == x) {
    return mid;
  }
  return -1;
}
// The difference in run-time is minimal. We did not gain much in performance and lost some in code readability.
