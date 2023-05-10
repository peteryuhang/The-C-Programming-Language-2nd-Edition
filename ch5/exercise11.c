#include <stdio.h>

/* 
 * Modify the programs entab and detab (written as exercise in Ch1) to
 * accept a list of tab stops as arguments. Use the default tab settings
 * if there are no arguments
 */
#define TAB_SIZE 8

int getstop(char *p);

// entab
// int main(int argc, char *argv[]) {
//   int nb, nt, p, c, ts;

//   nb = nt = 0;

//   ts = TAB_SIZE;
//   if (argc > 1) {
//     ts = getstop(argv[1]);
//   }
//   printf("Current tabsize is %d\n", ts);
//   for (p = 1; (c = getchar()) != EOF; ++p)
//     if (c == ' ') {
//       if ((p % ts) != 0)
//         ++nb;
//       else {
//         nb = 0;
//         ++nt;
//       }
//     } else {
//       for (; nt > 0; --nt)
//         putchar('\t');
//       if (c == '\t')
//         nb = 0;
//       else
//         for (; nb > 0; --nb)
//           putchar(' ');

//       putchar(c);

//       if (c == '\n')
//         p = 0;
//       else if (c == '\t')
//         p += (ts - (p - 1) % ts) - 1;
//     }

//   return 0;
// }

// detab
int main(int argc, char *argv[]) {
  int c, i, p, nbs, ts;

  ts = TAB_SIZE;
  if (argc > 1) {
    ts = getstop(argv[1]);
  }

  p = 1;
  while ((c=getchar()) != EOF) {
    if (c == '\t') {
      nbs = (ts - p % ts) % ts + 1;
      for (i = 0; i < nbs; ++i) {
        putchar(' ');
      }
      p += nbs;
    } else if (c == '\n') {
      putchar(c);
      p = 1;
    } else {
      ++p;
      putchar(c);
    }
  }
}

int getstop(char *p) {
  int stops;

  stops = 0;
  for (; *p; ++p)
    stops = 10 * stops + (*p - '0');
  return stops;
}