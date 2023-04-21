#include <stdio.h>

/* 
 * Write a program to "fold" long input lines into two or more short lines
 * after the last non-blank character that occurs before the n-th column of
 * input. Make sure you program does something intelligent with very long
 * lines, and if there are no blanks or tabs before the specified column
 */
#define LINE_SIZE 80

int getlinestored(char line[]);
void copy(char to[], char from[], int start, int size);

int main() {
  int i, cur_line_len, total_len;
  char lines[99999];
  char cur[LINE_SIZE * 2];

  cur_line_len = 0;
  while ((total_len = getlinestored(lines)) > 0) {
    printf("\n");
    for (i = 0; i < total_len; ++i) {
      if (lines[i] == '\n') {
        /*
         * copy size is cur_line_len because no need to put current 
         * charater (cur_line_len + 1) into consideration since we
         * will add in printf
         */
        copy(cur, lines, i - cur_line_len, cur_line_len);
        printf("%s\n", cur);
        cur_line_len = 0;
      } else if (cur_line_len >= LINE_SIZE) {
        /* 
         * copy size is cur_line_len + 1 because also need to put current
         * character(lines[i]) into consideration
         */
        copy(cur, lines, i - cur_line_len, cur_line_len + 1);

        // if the last word is longer, split later part into next line and connect by '-'
        if (i + 1 < total_len && lines[i] != ' ' && lines[i] != '\t'
              && lines[i + 1] != ' ' && lines[i + 1] != '\t') {
          cur[cur_line_len + 1] = '-';
          cur[cur_line_len + 2] = '\0';
        }

        printf("%s\n", cur);
        cur_line_len = 0;
      } else {
        ++cur_line_len;
      }
    }
  }

  return 0;
}

int getlinestored(char s[]) {
  int c, i;

  for (i = 0; (c=getchar()) != EOF; ++i)
    s[i] = c;

  s[i] = '\0';

  return i;
}

void copy(char to[], char from[], int start, int size) {
  int i;

  i = 0;
  while (i < size && (to[i] = from[start + i]) != '\0') {
    ++i;
  }

  if (to[i] != '\0') {
    to[i] = '\0';
  }
}
