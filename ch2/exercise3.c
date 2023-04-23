#include <stdio.h>

/* 
 * Write the function htoi(s), which converts a string of hexadecimal digits (including an optional 0x or 0X)
 * into its equivalent integer value. The allowable digits are 0 through 9, a through f, and A through F
 */
int htoi(char s[]);

int main() {
  // test & verify the htoi
  int r1 = htoi("F");
  printf("Hex %s convert to decimal integer is %d\n", "F", r1);

  int r2 = htoi("0x12F");
  printf("Hex %s convert to decimal integer is %d\n", "0x12F", r2);

  int r3 = htoi("0xc1");
  printf("Hex %s convert to decimal integer is %d\n", "0xc1", r3);

  int r4 = htoi("abc");
  printf("Hex %s convert to decimal integer is %d\n", "abc", r4);

  int r5 = htoi("a");
  printf("Hex %s convert to decimal integer is %d\n", "a", r5);

  int r6 = htoi("");
  printf("Hex %s convert to decimal integer is %d\n", "", r6);

  int r7 = htoi("-0xff");
  printf("Hex %s convert to decimal integer is %d\n", "-0xff", r7);

  int r8 = htoi("g");
  // printf("Hex %s convert to decimal integer is %d\n", "g", r7);
}

int htoi(char s[]) {
  int i, sign, n;

  sign = 1;
  i = 0;
  if (s[i] == '-') {
    sign = -1;
    ++i;
  }

  if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
    i += 2;
  }

  n = 0;
  for (; s[i] != '\0'; ++i) {
    if (s[i] >= '0' && s[i] <= '9') {
      n = n * 16 + (s[i] - '0');
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      n = n * 16 + (s[i] - 'a' + 10);
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      n = n * 16 + (s[i] - 'A' + 10);
    } else {
      printf("Error: The string contains unexpected character %c\n", s[i]);
      return -1;
    }
  }
  return sign * n;
}