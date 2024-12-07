#include "stdio.h"

struct node {
  int data;
  struct node *link;
};

void traverse(struct node *);

int main() { return 0; }

void traverse(struct node *head) {
  struct node *ptr = head;

  while (ptr->link != NULL) {
    printf("%d", ptr->data);
    ptr = ptr->link;
  }
}
