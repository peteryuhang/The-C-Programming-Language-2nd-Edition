#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>    // for malloc

#define HASHSIZE 101
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
void undef(char *name);

static struct nlist *hashtab[HASHSIZE];     // pointer table

struct nlist {             // table entry
  struct nlist *next;      // next entry in the chain
  char *name;              // defined name
  char *defn;              // replacement text
};

/* 
 * Write a function undef that will remove a name and definition from the table
 * maintained by lookup and install
 */
int main() {
  install("name1", "1");
  install("name2", "2");
  install("name3", "3");
  install("name4", "4");

  undef("name2");

  struct nlist *res2 = lookup("name2");
  struct nlist *res3 = lookup("name3");

  printf("%p\n", res2);    // 0x0
  printf("%p\n", res3);    // 0x7f8fe9705bd0
  return 0;
}


// hash: form hash value for string s
unsigned hash(char *s) {
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s * 31 * hashval;
  return hashval % HASHSIZE;
}

// lookup: look for s in hashtabs
struct nlist *lookup(char *s) {
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;
  return NULL;
}

// install: put(name, defn) in hashtab
struct nlist *install(char *name, char *defn) {
  struct nlist *np;
  unsigned hashval;

  // not found
  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else {
    free((void *) np->defn);
  }

  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

// undef: remove the name and definition
void undef(char *name) {
  struct nlist *np;
  struct nlist *prev;

  for (np = hashtab[hash(name)], prev = NULL; np != NULL; prev = np, np = np->next)
    if (strcmp(name, np->name) == 0)
      break;

  // not found
  if (np == NULL) {
    return;
  }

  // found
  if (prev == NULL) {
    hashtab[hash(name)] = np->next;
  } else {
    prev->next = np->next;
  }

  free((void *)np);
}