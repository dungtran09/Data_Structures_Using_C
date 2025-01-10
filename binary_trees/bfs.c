#include "stdio.h"
#include <stdlib.h>

struct Node {
  struct Node *left;
  struct Node *right;
  int data;
};

struct Queue {
  struct Node **array;
  int front;
  int rear;
  int size;
  int capacity;
};

struct Node *createNode(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

struct Queue *createQueue(int capacity) {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->array = (struct Queue **)malloc(sizeof(struct Queue));
  queue->capacity = capacity;
  queue->front = 0;
  queue->rear = -1;
  queue->size = 0;

  return queue;
}

int isEmpty(struct Queue *queue) { return queue->size == 0; }

void enqueue(struct Queue *queue, struct Node *node) {

  if (queue->size == queue->capacity) {
    printf("Queue is full!\n");
    return;
  }

  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->array[queue->rear] = node;
  queue->size++;
}

struct Node *dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty!\n");
    return NULL;
  }

  struct Node *node = queue->array[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size--;

  return node;
  ;
}

void BFS(struct Node *root) {
  if (root == NULL) {
    printf("Tree is Empty!\n");
    return;
  }

  struct Queue *queue = createQueue(100);
  enqueue(queue, root);

  printf("Level Order Travelsa: ");

  while (!isEmpty(queue)) {
    struct Node *currNode = dequeue(queue);
    printf("%d ", currNode->data);

    if (currNode->left) {
      enqueue(queue, currNode->left);
    }

    if (currNode->right) {
      enqueue(queue, currNode->right);
    }
  }

  printf("\n");

  free(queue->array);
  free(queue);
}

int main() {
  struct Node *root = createNode(8);
  root->left = createNode(3);
  root->right = createNode(10);
  root->left->left = createNode(1);
  root->left->right = createNode(6);
  root->right->right = createNode(14);
  root->left->right->left = createNode(4);
  root->left->right->right = createNode(7);
  root->right->right->left = createNode(13);

  BFS(root); // Thực hiện BFS trên cây
  return 0;
}
