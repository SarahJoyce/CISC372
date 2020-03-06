/* Implementation of the evens library. */
#include <stdio.h>
#include <stdlib.h>
#include "evens_lib.h"
// add other #includes as needed
int *new_array;

int *find_evens(int *p, int n, int *num_evens) {
 int numEvens = 0;
  for(int i=0; i<n; i++){
	if(p[i]%2 == 0){
	  numEvens++;
	}
  }
  *num_evens = numEvens;
  int e = 0;
  new_array = (int*)malloc(numEvens*sizeof(int));
  for(int i=0; i<n; i++){
     if(p[i]%2==0){
	new_array[e] = p[i];
	e++;
     }
  }
  return new_array;
}

void print_array(int * p, int n) {
  printf("The even numbers are: ");
  for (int i = 0; i < n; i++)
    printf("%d ", p[i]);
  printf("\n");
  fflush(stdout);
}
