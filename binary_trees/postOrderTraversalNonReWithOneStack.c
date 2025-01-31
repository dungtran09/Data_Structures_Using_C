#include "stdio.h"
#include "stdlib.h"

struct Node {
  struct Node *left;
  struct Node *right;
  int data;
};

struct Stack {
  struct Node **nodes;
  int capacity;
  int top;
  struct Node *prev;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

struct Stack *createStack(int capacity) {
  struct Stack *newStack = (struct Stack *)malloc(sizeof(struct Stack));
  newStack->capacity = capacity;
  newStack->top = -1;
  newStack->nodes = (struct Node **)malloc(capacity * sizeof(struct Node));
  newStack->prev = NULL;

  return newStack;
}

void push(struct Stack *stack, struct Node *node) {
  stack->nodes[++stack->top] = node;
}

struct Node *pop(struct Stack *stack) { return stack->nodes[stack->top--]; }

void postOrderWithOneStack(struct Node *root) {
  if (root == NULL) {
    return;
  }

  struct Stack *stack = createStack(100);

  push(stack, root);

  while (stack->top >= 0) {
    struct Node *currentNode = stack->nodes[stack->top];

    if (stack->prev == NULL || stack->prev->left == currentNode ||
        stack->prev->right == currentNode) {
      if (currentNode->left != NULL) {
        push(stack, currentNode->left);
      } else if (currentNode->right != NULL) {
        push(stack, currentNode->right);
      } else {
        printf("%d ", currentNode->data);
        pop(stack);
      }
    } else if (currentNode->left == stack->prev) {
      if (currentNode->right != NULL) {
        push(stack, currentNode->right);
      } else {
        printf("%d ", currentNode->data);
        pop(stack);
      }
    } else if (currentNode->right == stack->prev) {
      printf("%d ", currentNode->data);
      pop(stack);
    }

    stack->prev = currentNode;
  }
  printf("\n");

  free(stack->nodes);
  free(stack);
}

int main() {

  printf("Post Order Traversal With One Stack: ");
  struct Node *root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);

  postOrderWithOneStack(root);

  return 0;
}
