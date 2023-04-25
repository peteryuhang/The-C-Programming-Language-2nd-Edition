#include <stdio.h>

/* 
 * Write a function escape(s,t) that converts characters like newline and tab into visible escape
 * sequences like \n and \t as it copies the string t to s. Use a switch. Write a function for the
 * other direction as well, converting escape sequences into the real characters
 */
void getlines(char t[], int lim);
void escape(char s[], char t[]);

int main() {
  char t[99999];
  char s[99999 * 2];
  getlines(t, 99997);
  escape(s, t);

  printf("%s\n", s);
}

void getlines(char t[], int lim) {
  int c, i;

  for (i = 0; i < lim && (c=getchar()) != EOF; ++i)
    t[i] = c;

  t[i] = '\0';
}

void escape(char s[], char t[]) {
  int i, j;

  for (i = 0, j = 0; t[i] != '\0'; ++i) {
    switch (t[i])
    {
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    default:
      s[j++] = t[i];
      break;
    }
  }
  s[j] = '\0';
}
