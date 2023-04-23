#include <stdio.h>

/* 
 * Write an alternate version of squeeze(s1,s2) that deletes each character
 * in s1 that matches any character in the string s2
 */
void squeeze(char s1[], char s2[]);

int main() {
  char s1[] = "string1";
  char s2[] = "string2";

  squeeze(s1, s2);
  printf("The s1 after squeeze is %s\n", s1);
}

void squeeze(char s1[], char s2[]) {
  int i, j, k, match;

  for (i = 0, k = 0; s1[i] != '\0'; ++i) {
    match = 0;
    for (j = 0; s2[j] != '\0'; ++j) {
      if (s1[i] == s2[j]) {
        match = 1;
      }
    }

    if (!match) {
      s1[k++] = s1[i];
    }
  }

  s1[k] = '\0';
}
