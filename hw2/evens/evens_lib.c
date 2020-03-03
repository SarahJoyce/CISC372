/* Implementation of the evens library. */
#include <stdio.h>
#include "evens_lib.h"
// add other #includes as needed

int * find_evens(int * p, int n, int * num_evens) {
  // TODO: this is a stub.  Implement me.
  return NULL;
}

void print_array(int * p, int n) {
  printf("The even numbers are: ");
  for (int i = 0; i < n; i++)
    printf("%d ", p[i]);
  printf("\n");
  fflush(stdout);
}
