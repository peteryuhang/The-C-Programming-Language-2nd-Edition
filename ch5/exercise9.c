#include <stdio.h>


/* 
 * Rewrite the routines day_of_year and month_day with pointers instead of indexing
 */
static char daytab[2][13] = {
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
  { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

// day_of_year: set day of year from month & day
int day_of_year(int year, int month, int day);

// month_day: set month, day from day of year
void month_day(int year, int yearday, int *pmonth, int *pday);

int main() {
  int pmonth, pday;

  printf("Today is %dth day of current year\n", day_of_year(2023, 5, 10));

  month_day(2023, 130, &pmonth, &pday);
  printf("%dth day of current year is %d month %d day\n", 130, pmonth, pday);
}

int day_of_year(int year, int month, int day) {
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; i < month; ++i)
    day += *(*(daytab+leap)+i);
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
  for (i = 1; yearday > *(*(daytab+leap)+i); ++i)
    yearday -= *(*(daytab+leap)+i);
  *pmonth = i;
  *pday = yearday;
}

