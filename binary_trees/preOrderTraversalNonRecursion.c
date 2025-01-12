#include "stdio.h"
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

struct Stack {
  struct Node **items;
  int top;
  int capacity;
};

struct Stack *createStack(int capacity) {
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));

  stack->capacity = capacity;
  stack->top = -1;
  stack->items = (struct Node **)malloc(capacity * sizeof(struct Node *));

  return stack;
}

int isEmpty(struct Stack *stack) { return stack->top == -1; }

void push(struct Stack *stack, struct Node *node) {
  stack->items[++stack->top] = node;
}

struct Node *pop(struct Stack *stack) { return stack->items[stack->top--]; }

void preOderTraversal(struct Node *root) {
  if (root == NULL) {
    return;
  }

  struct Stack *stack = createStack(100);

  push(stack, root);

  while (!isEmpty(stack)) {
    struct Node *currentNode = pop(stack);

    printf("%d ", currentNode->data);

    if (currentNode->right) {
      push(stack, currentNode->right);
    }

    if (currentNode->left) {
      push(stack, currentNode->left);
    }
  }

  printf("\n");

  free(stack->items);
  free(stack);
}

int main() {

  struct Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);

  preOderTraversal(root);
  return 0;
}
