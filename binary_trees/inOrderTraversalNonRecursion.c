#include "stdio.h"
#include <stdlib.h>

struct Node {
  struct Node *left;
  struct Node *right;
  int data;
};

struct Stack {
  struct Node **items;
  int top;
  int capacity;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;

  return newNode;
}

struct Stack *createStack(int capacity) {
  struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));

  newStack->top = -1;
  newStack->capacity = capacity;
  newStack->items = (struct Node **)malloc(capacity * sizeof(struct Node *));

  return newStack;
}

int isEmpty(struct Stack *stack) { return stack->top == -1; }

void push(struct Stack *stack, struct Node *node) {
  stack->items[++stack->top] = node;
}

struct Node *pop(struct Stack *stack) { return stack->items[stack->top--]; }

void inOrderTraversalNonRecursion(struct Node *root) {
  if (root == NULL)
    return;

  struct Stack *stack = createStack(100);
  struct Node *currNode = root;

  while (!isEmpty(stack) || currNode != NULL) {
    while (currNode != NULL) {
      push(stack, currNode);
      currNode = currNode->left;
    }

    currNode = pop(stack);
    printf("%d ", currNode->data);
    currNode = currNode->right;
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

  inOrderTraversalNonRecursion(root);
  return 0;
}
