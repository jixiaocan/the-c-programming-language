#include <limits.h>
#include <stdio.h>

#define YES 1
#define NO 0
int htoi(char s[]);
// convert hex string s to integer
int main() {
  char s[] = "0x15";
  printf("hex %s convert to integer is %d", s, htoi(s));
}

int htoi(char s[]) {
  int hexdigit, i, inhex, n;

  i = 0;

  // skip 0x or 0X
  if (s[i] == '0') {
    ++i;
    if (s[i] == 'x' || s[i] == 'X') ++i;
  }

  n = 0;        // integer value to be returned
  inhex = YES;  // assume valid hex digit
  for (; inhex == YES; ++i) {
    if (s[i] >= '0' && s[i] <= '9')
      hexdigit = s[i] - '0';
    else if (s[i] >= 'a' && s[i] <= 'f')
      hexdigit = s[i] - 'a' + 10;
    else if (s[i] >= 'A' && s[i] <= 'F')
      hexdigit = s[i] - 'A' + 10;
    else
      inhex = NO;  // not a valid hex digit
    if (inhex == YES) n = 16 * n + hexdigit;
  }
  return n;
}