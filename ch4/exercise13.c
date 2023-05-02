#include <stdio.h>

/* 
 * Write a recursive version of the function reverse(s), which reverse
 * the string s in place
 */
void reverse(char s[], int, int);

int main() {
  char s[999] = "0123456789";

  reverse(s, 0, 9);
  printf("%s\n", s);
}

/* 
 * reverse: reverse the input string (recursive version)
 */
void reverse(char s[], int start, int end) {
  if (start >= end)
    return;

  int tmp = s[start];
  s[start] = s[end];
  s[end] = tmp;

  reverse(s, ++start, --end);
}
