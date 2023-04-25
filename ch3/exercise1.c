#include <stdio.h>

/* 
 * Our binary search makes two tests inside the loop, when one would suffice
 * (at the price of more tests outside). Write a version with only one test
 * inside the loop and measure the difference in run-time
 */
// int binarysearch_old(int x, int v[], int n);
int binarysearch_new(int x, int v[], int n);

int main() {
  int x = 5;
  int v[] = {1,2};
  printf("Result: %d\n", binarysearch_new(2, v, 2));
}

// int binarysearch_old(int x, int v[], int n) {
//   int low, high, mid;

//   low = 0;
//   high = n - 1;
//   while (low <= high) {
//     mid = (low+high) / 2;
//     if (x < v[mid])
//       high = mid - 1;
//     else if (x > v[mid])
//       low = mid + 1;
//     else
//       return mid;
//   }

//   return -1;
// }

int binarysearch_new(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;
  while (low + 1 < high) {
    mid = (low+high) / 2;
    if (x < v[mid])
      high = mid;
    else
      low = mid;
  }

  if (v[low] == x)
    return low;
  if (v[high] == x)
    return high;

  return -1;
}