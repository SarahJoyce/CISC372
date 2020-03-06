/* Driver for evens libary */
#include <stdio.h>
#include <stdlib.h>
#include "evens_lib.h"
// add other #includes as needed
// The main function is called at startup and calls all the other functions that run the program.
int main(int argc, char *argv[]) {
 int *p;
 int *num_evens;

  p = (int*)malloc(argc*sizeof(int));
  num_evens = (int*)malloc(argc*sizeof(int));

  for(int i = 1; i<argc; i++){
	p[i-1] = atoi(argv[i]);
  }

 int * evens = find_evens(p, argc-1, num_evens);

 print_array(evens, *num_evens);

 free(p);
 free(num_evens);
 free(evens);
  return 0;
}
