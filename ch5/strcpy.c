#include <stdio.h>

void strcpy_arr(char *s, char *t);
void strcpy_ptr1(char *s, char *t);
void strcpy_ptr2(char *s, char *t);
void strcpy_ptr3(char *s, char *t);

int main() {
  char s[100];

  strcpy_ptr3(s, "hello, world\n");
  printf("%s", s);
}

/* strcpy: copy t to s; array subscript version */
void strcpy_arr(char *s, char *t) {
  int i;

  i = 0;
  while ((s[i] = t[i]) != '\0')
    i++;
}

/* strcpy: copy t to s; pointer version 1 */
void strcpy_ptr1(char *s, char *t) {
  while ((*s = *t) != '\0') {
    s++;
    t++;
  }
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy_ptr2(char *s, char *t) {
  while ((*s++ = *t++) != '\0')
    ;
}

/* strcpy: copy t to s; pointer version 3 */
void strcpy_ptr3(char *s, char *t) {
  while ((*s++ = *t++))
    ;
}