#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getword.c"

// linked list of line numbers
struct linklist {
  int lnum;
  struct linklist *ptr;
};

struct tnode {
  char *word;
  struct linklist *lines;  // line numbers
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100

struct tnode *addtreex(struct tnode *, char *, int);
int noiseword(char *);
void treexprint(struct tnode *);
int getword(char *, int);

// Write a cross-referencer that prints a list of all words in a document, and
// for each word, a list of the line numbers on which it occurs.
int main(int argc, char *argv[]) {
  struct tnode *root;
  char word[MAXWORD];
  int linenum = 1;
  root = NULL;
  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0]) && noiseword(word) == -1) {
      root = addtreex(root, word, linenum);
    } else if (word[0] == '\n') {
      linenum++;
    }
  }
  treexprint(root);
  return 0;
}

struct tnode *talloc(void);
char *strdup2(char *s);
struct linklist *lalloc(void);
void addln(struct tnode *, int);

// add a node with w, at or below p
struct tnode *addtreex(struct tnode *p, char *w, int linenum) {
  int cond;
  if (p == NULL) {
    p = talloc();  // make a new node
    p->word = strdup2(w);
    p->lines = lalloc();
    p->lines->lnum = linenum;
    p->lines->ptr = NULL;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    addln(p, linenum);
  } else if (cond < 0) {
    p->left = addtreex(p->left, w, linenum);
  } else if (cond > 0) {
    p->right = addtreex(p->right, w, linenum);
  }
  return p;
}

// add a line number to the linked list
void addln(struct tnode *p, int linenum) {
  struct linklist *temp;

  temp = p->lines;
  // 找到最后的节点，一行可能出现多次
  while (temp->ptr != NULL && temp->lnum != linenum) {
    temp = temp->ptr;
  }
  // 在最后的节点插入新的节点
  if (temp->lnum != linenum) {
    temp->ptr = lalloc();
    temp->ptr->lnum = linenum;
    temp->ptr->ptr = NULL;
  }
}

// in-order print of tree p if p->match == YES
void treexprint(struct tnode *p) {
  struct linklist *temp;

  if (p != NULL) {
    treexprint(p->left);
    printf("%10s: ", p->word);
    for (temp = p->lines; temp != NULL; temp = temp->ptr) {
      printf("%4d ", temp->lnum);
    }
    printf("\n");
    treexprint(p->right);
  }
}

// make a linklist node
struct linklist *lalloc(void) {
  return (struct linklist *)malloc(sizeof(struct linklist));
}

// identify word as a noise word
int noiseword(char *w) {
  static char *nw[] = {"a",  "an", "and",  "are", "in",   "is",
                       "of", "or", "that", "the", "this", "to"};
  int cond, mid;
  int low = 0;
  int high = sizeof(nw) / sizeof(char *) - 1;

  while (low <= high) {
    mid = (low + high) / 2;
    if ((cond = strcmp(w, nw[mid])) < 0)
      high = mid - 1;
    else if (cond > 0)
      low = mid + 1;
    else
      return mid;
  }
  return -1;
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