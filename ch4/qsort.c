#include <stdio.h>


void qsort(int[], int, int);

int main() {
  int arr[] = { 3,4,5,1,0,-9,10,2,1,0 };

  qsort(arr, 0, 9);
  
  int i;

  printf("{");
  for (i = 0; i < 10; ++i)
    printf("%d,", arr[i]);
  printf("}\n");

  return 0;
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
  int i, last;
  void swap(int v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; ++i)
    if (v[i] < v[left])
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

void swap(int v[], int i, int j) {
  int tmp = v[i];
  v[i] = v[j];
  v[j] = tmp;
}