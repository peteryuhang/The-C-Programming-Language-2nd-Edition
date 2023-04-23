#include <stdio.h>

/* 
 * Write the function any(s1, s2), which return the first location in the string
 * s1 where any character from the string s2 occurs, or -1 if s1 contains no characters
 * from s2. (The standard library function strpbrk does the same job but returns a pointer
 * to the location)
 */
int any(char s1[], char s2[]);

int main() {
  printf("The result for (%s, %s) is %d\n", "123456", "234", any("123456", "234"));
  printf("The result for (%s, %s) is %d\n", "123456", "654321", any("123456", "654321"));
  printf("The result for (%s, %s) is %d\n", "123456", "", any("123456", ""));
  printf("The result for (%s, %s) is %d\n", "", "123", any("123456", ""));
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i = 0; s1[i] != '\0'; ++i) {
    for (j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }

  return -1;
}