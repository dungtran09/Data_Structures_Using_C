#include "stdio.h"
#include <stdlib.h>
#include <time.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *searchElement(struct Node *, int);
struct Node *createdTree(struct Node *);

int main() {
  struct Node *tree = NULL;
  struct Node *root = createdTree(tree);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = 10;
  root->left = NULL;
  root->right = NULL;

  struct Node *result = searchElement(root, 20);

  if (result == NULL) {
    printf("False\n");
  } else {
    printf("True\n");
  }

  return 0;
}

struct Node *createdTree(struct Node *root) { return root = NULL; }
struct Node *searchElement(struct Node *tree, int val) {
  if (tree == NULL) {
    return NULL;
  }
  if (tree->data == val) {
    return tree;
  } else if (tree->data < val) {
    return searchElement(tree->left, val);
  } else {
    return searchElement(tree->right, val);
  }
}
