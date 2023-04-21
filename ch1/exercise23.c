#include <stdio.h>

/* 
 * Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest
 */
int getlinestored(char line[]);

int main() {
  int i, j, total_len;
  int quote, ch, inline_comment, block_comment;
  char lines[999999];

  i = j = quote = ch = inline_comment = block_comment = 0;
  total_len = getlinestored(lines);
  for (; i < total_len; ++i) {
    if (i+1 < total_len && lines[i] == '/' && lines[i+1] == '/' && !quote) {
      inline_comment = 1;
      ++i;
      continue;
    }

    if (i+1 < total_len && lines[i] == '/' && lines[i+1] == '*' && !quote) {
      block_comment = 1;
      ++i;
      continue;
    }

    if (i+1 < total_len && lines[i] == '*' && lines[i+1] == '/' && !quote) {
      block_comment = 0;
      ++i;
      continue;
    }

    if (lines[i] == '\n' && inline_comment) {
      inline_comment = 0;
    }

    if (inline_comment || block_comment) {
      continue;
    }

    if (lines[i] == '\"' && !ch) {
      quote = 1 - quote;
    }

    if (lines[i] == '\'' && !quote) {
      ch = 1 - ch;
    }

    lines[j++] = lines[i];
  }

  lines[j] = '\0';
  printf("%s\n", lines);

  return 0;
}

int getlinestored(char s[]) {
  int c, i;

  for (i = 0; (c=getchar()) != EOF; ++i)
    s[i] = c;

  s[i] = '\0';

  return i;
}
