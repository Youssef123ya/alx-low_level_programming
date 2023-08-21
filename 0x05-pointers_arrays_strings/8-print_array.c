#include <stdio.h>

/**
 * print_array - A function that prints n elements of an array
 * @a: Array name
 * @n: Number of elements of the array to be printed
 */
void print_array(int *a, int n)
{
  if (n > 0)
  {
    int i;

    for (i = 0; i < n - 1; i++)
    {
      printf("%d, ", a[i]);
    }

    printf("%d", a[n - 1]);
  }

  printf("\n");
}

int main(void) {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  print_array(arr, size);

  return 0;
}
