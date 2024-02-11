#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

struct node {
  int data;
  struct node *next;
};

struct node* insert_at_begining(struct node *, int);
void traversal(struct node*);

int main(int argc, char *argv[]) {
  
  struct node *start = NULL;

  start = (struct node *) malloc(sizeof (struct node));
  start->data = 1;
  start->next = NULL;

  struct node *ptr = insert_at_begining(start, 2);
  ptr = insert_at_begining(ptr, 3);
  ptr = insert_at_begining(ptr, 4);

  traversal(ptr);

  return 0;
}

struct node* insert_at_begining(struct node *head, int data) {
  struct node* newNode = (struct node *)malloc(sizeof(struct node));
  
  newNode->next = head;
  newNode->data = data;

  head = newNode;

  return head;
}

void traversal(struct node * head) {
  
  struct node* ptr = head;

  while (ptr != NULL) {
    printf("%d \t", ptr->data);

    ptr = ptr->next;
  }
}

