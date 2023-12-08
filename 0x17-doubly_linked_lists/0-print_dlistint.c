#include "lists.h"

/**
 * print_dlistint - prints all the elements of a
 * dlistint_t list
 *
 * @h: head of the list
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
   int count; // Variable to keep track of the number of nodes

   count = 0; // Initialize count to 0

   // If the head of the list is NULL, return count (which is 0)
   if (h == NULL)
       return (count);

   // Traverse to the start of the list
   while (h->prev != NULL)
       h = h->prev;

   // Traverse the list and print each node
   while (h != NULL)
   {
       printf("%d\n", h->n); // Print the value of the current node
       count++; // Increment the count
       h = h->next; // Move to the next node
   }

   return (count); // Return the count
}
