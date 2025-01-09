
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int front = -1;
int rear = -1;

int queue[SIZE];

void enqueue(int);

int main(int argc, char *argv[]) {

  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(40);

  return EXIT_SUCCESS;
}

void enqueue(int value) {
  if (rear == SIZE) {
    printf("Queue is Full\n");
    return;
  }

  if (front == -1) {
    front = 0;
  }

  rear++;
  queue[rear] = value;
  printf("Endqueued to queue!\n");
}
