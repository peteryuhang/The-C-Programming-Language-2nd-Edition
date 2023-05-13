#include <stdio.h>

/* 
 * Extend entab and detab to accept the shorthand
 *      entab -m +n
 * to mena tab stops every n columns, starting at column m.
 * Choose convenient (for the user) default behavior
 */
#define TAB_SIZE 8

int getstop(char *p);
void getflag(int argc, char *argv[], int *start, int *ts);

// entab
// int main(int argc, char *argv[]) {
//   int nb, nt, p, c, ts, st;

//   nb = nt = 0;

//   // default value
//   st = 0;
//   ts = TAB_SIZE;

//   getflag(argc, argv, &st, &ts);
//   printf("entab: Tab stops every %d columns, starting at column %d\n", ts, st);

//   for (p = 1; (c = getchar()) != EOF; ++p)
//     if (p >= st) {
//       if (c == ' ') {
//         if ((p % ts) != 0)
//           ++nb;
//         else {
//           nb = 0;
//           ++nt;
//         }
//       } else {
//         for (; nt > 0; --nt)
//           putchar('\t');
//         if (c == '\t')
//           nb = 0;
//         else
//           for (; nb > 0; --nb)
//             putchar(' ');

//         putchar(c);

//         if (c == '\n')
//           p = 0;
//         else if (c == '\t')
//           p += (ts - (p - 1) % ts) - 1;
//       }
//     }

//   return 0;
// }

// detab
int main(int argc, char *argv[]) {
  int c, i, p, nbs, st, ts;

  // default value
  st = 0;
  ts = TAB_SIZE;

  getflag(argc, argv, &st, &ts);
  printf("detab: Tab stops every %d columns, starting at column %d\n", ts, st);

  p = 1;
  while ((c=getchar()) != EOF) {
    if (c == '\t') {
      nbs = (ts - p % ts) % ts + 1;
      if (p >= st)
        for (i = 0; i < nbs; ++i) {
          putchar(' ');
        }
      else
        putchar('\t');
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

/* getflag: parse the options from the command line input */
void getflag(int argc, char *argv[], int *start, int *ts) {
  int c;

  while (--argc > 0 && *++argv)
    switch (*argv[0])
    {
    case '-':
      *start = getstop(++argv[0]);
      break;
    case '+':
      *ts = getstop(++argv[0]);
      break;
    default:
      printf("find: illegal option %c\n", c);
      break;
    }
}

/* getstop: parse the tabstops stored in string number into integer */
int getstop(char *p) {
  int stops;

  stops = 0;
  for (; *p; ++p)
    stops = 10 * stops + (*p - '0');
  return stops;
}
