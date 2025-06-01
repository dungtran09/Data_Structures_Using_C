#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *left;
  struct Node *right;
  int data;
  int height;
};

struct Node *createNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->left = NULL;
  node->right = NULL;
  node->data = data;
  node->height = 1;

  return node;
}

int max(int x, int y) { return (x > y) ? x : y; }

int height(struct Node *node) {
  if (node == NULL) {
    return 0;
  }

  return node->height;
}

int getBalence(struct Node *node) {
  if (node == NULL) {
    return 0;
  }

  return height(node->left) - height(node->right);
}

struct Node *leftRotate(struct Node *x) {
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  // rotate
  y->left = x;
  x->right = T2;

  // update height after rotated
  x->height = 1 + max(height(x->left), height(x->right));
  y->height = 1 + max(height(y->left), height(y->right));

  // current node is y and hav to return y (new root of tree)
  return y;
}

struct Node *rightRotate(struct Node *y) {
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  // rotate
  x->right = y;
  y->left = T2;

  // updated height after rotated
  y->height = 1 + max(height(y->left), height(y->right));
  x->height = 1 + max(height(x->left), height(x->right));

  // root current node is x and have to return x (new root of tree)
  return x;
}

void inOrder(struct Node *node) {
  if (node != NULL) {
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
  }
}

struct Node *insert(struct Node *node, int data) {

  if (node == NULL) {
    return createNode(data);
  }

  if (data < node->data) {
    node->left = insert(node->left, data);
  } else if (data > node->data) {
    node->right = insert(node->right, data);
  } else {
    return node;
  }

  node->height = 1 + (max(height(node->left), height(node->right)));

  int balence = getBalence(node);

  // LL rotate
  if (balence > 1 && data < node->left->data) {
    return rightRotate(node);
  }

  // RR rotate
  if (balence < -1 && data > node->right->data) {
    return leftRotate(node);
  }

  // LR rotate
  if (balence > 1 && data > node->left->data) {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // RL rotate
  if (balence < -1 && data < node->right->data) {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}
int main() {

  struct Node *root = NULL;

  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  printf("Traversal inorder AVL: ");
  inOrder(root);
  printf("\n");

  return 0;
}
