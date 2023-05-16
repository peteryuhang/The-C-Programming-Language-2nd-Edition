#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline_m(char *line, int max);

/* find: print lines that match pattern from 1st arg */
// int main(int argc, char *argv[]) {
//   char line[MAXLINE];
//   int found = 0;

//   if (argc != 2)
//     printf("Usage: find pattern\n");
//   else
//     while (getline_m(line, MAXLINE) > 0)
//       if (strstr(line, argv[1]) != NULL) {
//         printf("%s", line);
//         found++;
//       }
//   return found;
// }

/* find: print lines that match pattern from 1st arg, find -nx pattern */
int main(int argc, char *argv[]) {
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;

  // (*++argv)[0] represent the first character of corresponding arg
  while (--argc > 0 && (*++argv)[0] == '-')
    // *++argv[0] increment the corresponding arg which argv pointed to
    while (c = *++argv[0])
      switch (c)
      {
      case 'x':
        except = 1;
        break;
      case 'n':
        number = 1;
        break;
      default:
        printf("find: illegal option %c\n", c);
        argc = 0;
        found = -1;
        break;
      }

  if (argc != 1)
    printf("Usage: find  -x -n pattern\n");
  else
    while (getline_m(line, MAXLINE) > 0) {
      lineno++;
      if ((strstr(line, *argv) != NULL) != except) { // **
        if (number)
          printf("%ld: ", lineno);
        printf("%s", line);
        found++;
      }
    }
  return found;
}

/* getline_m: Read line into s, return length */
int getline_m(char *s, int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++s, ++i)
    *s = c;
  
  if (c == '\n') {
    *s++ = c;
    i++;
  }
  *s = '\0';

  return i;
}