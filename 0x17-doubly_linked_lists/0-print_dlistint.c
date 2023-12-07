#include <stdio.h>

typedef struct dlistint_s
{
   int n;
   struct dlistint_s *prev;
   struct dlistint_s *next;
} dlistint_t;

size_t print_dlistint(const dlistint_t *h)
{
   int count;

   count = 0;

   if (h == NULL)
       return (count);

   while (h->prev != NULL)
       h = h->prev;

   while (h != NULL)
   {
       printf("%d\n", h->n);
       count++;
       h = h->next;
   }

   return (count);
}
