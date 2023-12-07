#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
   int data;
   struct Node *next;
   struct Node *prev;
} Node;

// Function to print the list
void printList(Node *head) {
   Node *current = head;
   while (current != NULL) {
       printf("%d ", current->data);
       current = current->next;
   }
   printf("\n");
}

// Function to insert a node at the front of the list
Node* insertAtFront(Node *head, int data) {
   Node *newNode = malloc(sizeof(Node));
   if (newNode == NULL) {
       printf("Error: Can't malloc\n");
       exit(EXIT_FAILURE);
   }
   newNode->data = data;
   newNode->next = head;
   newNode->prev = NULL;
   if (head != NULL) {
       head->prev = newNode;
   }
   head = newNode;
   return head;
}

int main(void) {
   Node *head = NULL;
   head = insertAtFront(head, 8);
   head = insertAtFront(head, 9);
   printList(head);
   free(head);
   return EXIT_SUCCESS;
}
