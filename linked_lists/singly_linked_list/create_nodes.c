#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

struct node *create_new_node(int);

int main(int argc, char *argv[]) {

  struct node *head = NULL;

  return 0;
}

struct node *create_new_node(int data) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->link = NULL;

  return newNode;
}
