#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};
// 基于 5_7, 添加数据校验
// set day of year from month & day
int day_of_year(int year, int month, int day) {
  int i, leap;
  // 判断是否是闰年
  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  // 校验 month
  if (month < 1 || month > 12) return -1;
  // 校验 day
  if (day < 1 || day > daytab[leap][month]) return -1;
  for (i = 1; i < month; i++) {
    day += daytab[leap][i];
  }
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  if (year < 1) {
    *pmonth = -1;
    *pday = -1;
    return;
  }

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++) {
    yearday -= daytab[leap][i];
  }
  if (i > 12 && yearday > daytab[leap][12]) {
    *pmonth = -1;
    *pday = -1;
  } else {
    *pmonth = i;
    *pday = yearday;
  }
}

int main() {
  printf("%d\n", day_of_year(2020, 1, 15));
  printf("%d\n", day_of_year(2020, 2, 1));
  printf("%d\n", day_of_year(2020, 22, 1));
  int *pmonth;
  int *pday;
  int i, j = 0;
  pmonth = &i;
  pday = &j;
  month_day(2021, 15, pmonth, pday);

  printf("%d %d %d\n", 2021, *pmonth, *pday);
}