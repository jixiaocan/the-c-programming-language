#include <stdio.h>

void shellsort(int v[], int n);

int main() {
  int arr[] = {7, 3, 1, 9, 5, 4, 2, 8, 6};
  shellsort(arr, 9);
  for (int i = 0; i < 9; i++) {
    printf("%d ", arr[i]);
  }
}

void shellsort(int v[], int n) {
  int gap, i, j, temp;
  for (gap = n / 2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        // swap
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
    }
  }
}