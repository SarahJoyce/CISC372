/* Driver for evens libary */
#include <stdio.h>
#include <stdlib.h>
#include "evens_lib.h"
// add other #includes as needed
int *p;
int n;
int e;
int *num_evens;
// The main function is called at startup and calls all the other functions that run the program.
int main(int argc, char *argv[]) {
  p = (int*)malloc(argc*sizeof(int));
  
  for(int i = 0; i<argc; i++){
	p[i] = atoi(argv[i]);
  }

  n = sizeof(p) / sizeof(p[0]);

 find_evens(p, n, num_evens);

 e = sizeof(num_evens)/sizeof(num_evens[0]);

 print_array(num_evens, e);

 free(p);
 free(num_evens);
  return 0;
}
