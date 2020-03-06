/* Program for ragged question */
#include <stdio.h>
#include <stdlib.h>
// add other #includes as needed

// TODO: create two global variables: 
//   1. lengths. Type: pointer-to-int
//   2. data. Type: pointer-to-pointer-to-int.
int *lengths;
int **data;

// The main function is the first thing called when a program is executed. It can call other functions in the program.
int main(int argc, char **argv) {
  //allocate space
  lengths = (int*)malloc(argc*sizeof(int));
  data = (int**)malloc(argc*sizeof(int*));
  //put args from argv into lengths array
  for(int i=0; i<argc; i++){
    lengths[i] = atoi(argv[i]);	
  }
  
  //fill data array
  int c = 0;
  for(int i=0; i<argc; i++){
  data[i] = malloc(lengths[i]*sizeof(int));
    for(int j=0; j<lengths[i]; j++){
	data[i][j] = c;
	c++;
    }
  }

  //print
  for(int i = 0; i<argc; i++){
    for(int j=0; j<lengths[i]; j++){
	printf("%d ", data[i][j]);
    }printf("\n");
  }

  //free things
  free(*data);
  free(data);
  free(lengths);
  return 0;
}
