#include <stdio.h>

/* 
 * shell sort is an optimization version of insertion sort
 * It can avoid large operation on certain special cases (eg. 2,3,4,5,6,7,1)
 * 
 * The worest time complexity still O(n^2), but its avg time complexity can reach O(nlogn)
 * which is better than original insertion sort
 */
void insertion_sort(int v[], int n, int gap);
void shell_sort(int v[], int n);

int main() {
  int v[] = {1,2,3,4,5,6,0};
  int x = 7;
  shell_sort(v, x);
  
  int i;
  for (i = 0; i < x; ++i)
    printf("%d ", v[i]);
  printf("\n");
}

/* 
 * Normal insertion sort, the gap is 1, this insertion sort is design for shell_sort
 */
void insertion_sort(int v[], int n, int gap) {
  int i, j, tmp;
  for (i = gap; i < n; ++i) {
    for (j = i - gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
      tmp = v[j];
      v[j] = v[j+gap];
      v[j+gap] = tmp;
    }
  }
}

void shell_sort(int v[], int n) {
  int i, j, gap, tmp;

  for (gap = n/2; gap > 0; gap /= 2) {
    insertion_sort(v, n, gap);
  }
}
