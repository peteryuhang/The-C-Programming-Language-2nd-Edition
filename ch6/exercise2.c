#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>    // for malloc

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *, char *, int n);
int getword(char *, int);
struct tnode *talloc(void);
char *my_strdup(char *s);

/* 
 * Write a program that reads a C program and prints in alphabetical order each group of
 * variable names that are identical in the first 6 characters, but different somewhere
 * thereafter. Don't count words within strings and comments.
 * Make 6 a parameter that can be set from command line
 */

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

/* word frequency count */
int main(int argc, char *argv[]) {
  struct tnode *root;
  char word[MAXWORD];
  int n;

  root = NULL;
  n = getn(argv[0]);
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word, n);
  treeprint(root, NULL);
  return 0;
}

/* getn: parse the tabstops stored in string number into integer */
int getn(char *p) {
  int n;

  n = 0;
  for (; *p; ++p)
    n = 10 * n + (*p - '0');
  return n;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
  int cond;
  int i;

  if (p == NULL) { // a new word has arrived
    p = talloc();
    p->word = my_strdup(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;
  } else if (cond < 0) {
    p->left = addtree(p->left, w);
  } else {
    p->right = addtree(p->right, w);
  }
  return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p, char *prev, int n) {
  if (p != NULL) {
    treeprint(p->left, p->word, n);
    if (is_same_group(p->word, prev, n) == 0) 
      printf("\n==============================\n");
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right, p->word, n);
  }
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}

/* my_strdup: make a duplicate of s */
char *my_strdup(char *s) {
  char *p;

  p = (char *) malloc(strlen(s)+1);      /* +1 for '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}

int is_same_group(char *s1, char *s2, int n) {
  int i;

  i = 0;
  while (i < n) {
    if (s1[i] != s2[i]) {
      return 0;
    }
    i++;
  }
  return 1;
}

enum { NORMAL, LINE_COMMENTS, BLOCK_COMMENTS, STRING_CONSTANT, PREPROCESSOR };
int type = NORMAL;            // record current word context
/*
 * getword: get next word or character from input
 */
int getword(char *word, int lim) {
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c=getch()))
    if (c == '\n' && (type == LINE_COMMENTS || type == PREPROCESSOR)) {
      type = NORMAL;
    }

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c) && c != '_') {
    if (c == '/' && (type == NORMAL || type == PREPROCESSOR)) {
      if ((c=getch()) && c == '/') {
        type = LINE_COMMENTS;
      } else if (c == '*') {
        type = BLOCK_COMMENTS;
      }
    } else if (c == '*' && type == BLOCK_COMMENTS) {
      if ((c=getch()) && c == '/') {
        type = NORMAL;
      }
    } else if (c == '#' && type == NORMAL) {
      type = PREPROCESSOR;
    }
    *w = '\0';
    return c;
  }

  if (type != NORMAL) {
    *w = '\0';
    return c;
  }

  for (; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];      /* buffer for ungetch */
int bufp = 0;           /* next free position in buf */

int getch(void) {       /* get a (possibly pushed back) character */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {     /* push character back on input */
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters");
  else
    buf[bufp++] = c;
}
