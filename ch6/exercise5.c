#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>    // for malloc

#define HASHSIZE 101
unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);

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

  struct nlist *res = lookup("name2");

  printf("%s\n", res->defn);
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