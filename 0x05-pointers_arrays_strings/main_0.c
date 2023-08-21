#include <stdio.h>
#include "main.h"

int main(void) {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  print_array(arr, size);

  return 0;
}
