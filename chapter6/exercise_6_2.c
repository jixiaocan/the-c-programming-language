#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getword.c"

struct tnode {
  char *word;
  int match;  // match found
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100
#define YES 1
#define NO 0

struct tnode *addtreex(struct tnode *, char *, int, int *);
void treexprint(struct tnode *);
int getword(char *, int);

// 基于6_5_tnode
// print in alphabetic order each group of variable names
// identical in the first num characters (default 6)
int main(int argc, char *argv[]) {
  struct tnode *root;
  char word[MAXWORD];
  int found = NO;  // YES if match was found
  int num;         // number of the first ident. chars
  num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
  printf("num=%d\n", num);

  root = NULL;
  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0]) && strlen(word) >= num)
      root = addtreex(root, word, num, &found);
    found = NO;
  }
  treexprint(root);
  return 0;
}

struct tnode *talloc(void);
char *strdup2(char *s);
int compare(char *, struct tnode *, int, int *);

// add a node with w, at or below p
struct tnode *addtreex(struct tnode *p, char *w, int num, int *found) {
  int cond;
  if (p == NULL) {
    p = talloc();  // make a new node
    p->word = strdup2(w);
    p->match = *found;
    p->left = p->right = NULL;
  } else if ((cond = compare(w, p, num, found)) < 0) {
    p->left = addtreex(p->left, w, num, found);
  } else if (cond > 0) {
    p->right = addtreex(p->right, w, num, found);
  }
  return p;
}

// compare words and update p->match
int compare(char *s, struct tnode *p, int num, int *found) {
  int i;
  char *t = p->word;

  for (i = 0; *s == *t; i++, s++, t++) {
    if (*s == '\0') return 0;
  }
  if (i >= num) {
    *found = YES;
    p->match = YES;
  }
  return *s - *t;
}

// in-order print of tree p if p->match == YES
void treexprint(struct tnode *p) {
  if (p != NULL) {
    treexprint(p->left);
    if (p->match) printf("%s\n", p->word);
    treexprint(p->right);
  }
}

// make a tnode
struct tnode *talloc(void) {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

/* make a duplicate of s */
char *strdup2(char *s) {
  char *p;
  p = (char *)malloc(strlen(s) + 1);  // +1 for '\0'
  if (p != NULL) strcpy(p, s);
  return p;
}