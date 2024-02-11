#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *link;
};

struct node* create_new_node (int);
struct node* insert_at_last (struct node *, int);
struct node* insert_at_begin (struct node*, int);
void display(struct node *);

int main(int argc, char *argv[]) {
  
  struct node *head = NULL;
 
  head = create_new_node(10);
  struct node *ptr = head;
  
  ptr = insert_at_last(ptr, 2000);
  ptr = insert_at_last(ptr, 3000);
  ptr = insert_at_last(ptr, 4000);

  ptr = insert_at_begin(head, 5);
  ptr = insert_at_begin(ptr, 6);
  ptr = insert_at_begin(ptr, 7);

  // ptr = head;
  display(ptr);

  return 0;
}

struct node* create_new_node(int data) {
  struct node* newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->link = NULL;

  return newNode;
}

struct node* insert_at_begin (struct node* ptr, int data) {
  
  struct node* temp = create_new_node(data);

  temp->link = ptr;
  ptr = temp; 

  return ptr;

}

struct node* insert_at_last(struct node *ptr, int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));

  temp->data = data;
  temp->link = NULL;

  ptr->link = temp;

  return temp;

}


void display(struct node *ptr) {
  if(ptr == NULL) {
    printf("%s", "Single linked list is empty!");
    return;
  }

  while (ptr != NULL) {
    printf("%d \t", ptr->data);
    ptr = ptr->link;
  }

}
