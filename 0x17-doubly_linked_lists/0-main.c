#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
   dlistint_t *head; // Declare a pointer to the head of the doubly linked list
   dlistint_t *new; // Declare a pointer to a new node
   dlistint_t hello = {8, NULL, NULL}; // Create a node with value 8 and NULL next and prev pointers
   size_t n; // Declare a variable to hold the number of elements in the list

   head = &hello; // Set the head of the list to the 'hello' node
   new = malloc(sizeof(dlistint_t)); // Allocate memory for a new node
   if (new == NULL) // Check if the memory allocation was successful
   {
       dprintf(2, "Error: Can't malloc\n"); // If not, print an error message and return failure
       return (EXIT_FAILURE);
   }
   new->n = 9; // Set the value of the new node to 9
   head->prev = new; // Set the prev pointer of the 'hello' node to the new node
   new->next = head; // Set the next pointer of the new node to the 'hello' node
   new->prev = NULL; // Set the prev pointer of the new node to NULL (since it's the first node)
   head = new; // Set the head of the list to the new node
   n = print_dlistint(head); // Print the list and get the number of elements
   printf("-> %lu elements\n", n); // Print the number of elements
   free(new); // Free the memory allocated for the new node
   return (EXIT_SUCCESS); // Return success
}
