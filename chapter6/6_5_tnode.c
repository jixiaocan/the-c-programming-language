#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include "getword.c"

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};

#define MAXWORD 100
struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

// 使用二叉树计算每个单词出现的次数
int main() {
  struct tnode *root;
  char word[MAXWORD];
  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0])) root = addtree(root, word);
  treeprint(root);
  return 0;
}

struct tnode *talloc(void);
char *strdup2(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
  int cond;
  if (p == NULL) {
    p = talloc();  // make a new node
    p->word = strdup2(w);
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
// 先打印左节点，再打印右节点
void treeprint(struct tnode *p) {
  if (p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
}

#include <stdlib.h>

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