#include "stdio.h"
#include <stdlib.h>

struct Node {
  struct Node *left;
  struct Node *right;
  int data;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;

  return newNode;
}

struct Stack {
  struct Node **nodes;
  int capacity;
  int top;
};

struct Stack *createStack(int capacity) {
  struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));

  newStack->top = -1;
  newStack->capacity = capacity;
  newStack->nodes = (struct Node **)malloc(capacity * sizeof(struct Node));

  return newStack;
}

void push(struct Stack *stack, struct Node *node) {
  stack->nodes[++stack->top] = node;
}

struct Node *pop(struct Stack *stack) { return stack->nodes[stack->top--]; };

void postOrderTraversalWithTwoStack(struct Node *root) {
  if (root == NULL) {
    return;
  }

  struct Stack *stack1 = createStack(100);
  struct Stack *stack2 = createStack(100);

  push(stack1, root);

  while (stack1->top >= 0) {
    struct Node *currentNode = pop(stack1);
    push(stack2, currentNode);

    if (currentNode->left != NULL) {
      push(stack1, currentNode->left);
    }

    if (currentNode->right != NULL) {
      push(stack1, currentNode->right);
    }
  }

  while (stack2->top >= 0) {
    printf("%d ", stack2->nodes[stack2->top--]->data);
  }

  printf("\n");
}
int main() {

  printf("Post Order Traversal With Two Stack: ");
  struct Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);

  postOrderTraversalWithTwoStack(root);

  return 0;
}
