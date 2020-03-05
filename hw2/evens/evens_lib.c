/* Implementation of the evens library. */
#include <stdio.h>
#include <stdlib.h>
#include "evens_lib.h"
// add other #includes as needed

int * find_evens(int * p, int n, int * num_evens) {
 int j = 0;
  for(int i=0; i<n; i++){
	if((p[i])%2 == 0){
	  j++;
	}
  }
  num_evens = (int*)malloc(j*sizeof(int));
  j=0;
  for(int i=0; i<n; i++){
	if((p[i])%2==0){
	  num_evens[j]==p[i];
	  j++;
	}
  }
  return num_evens;
}

void print_array(int * p, int n) {
  printf("The even numbers are: ");
  for (int i = 0; i < n; i++)
    printf("%d ", p[i]);
  printf("\n");
  fflush(stdout);
}
