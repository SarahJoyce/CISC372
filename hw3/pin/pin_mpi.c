/* This program computes a rather funny function on integers.
 * Given any nonnegative integer i, let f(i) be the integer
 * specified by the first 4 digits after the decimal point in the decimal
 * expansion of sin^2(i).
 * Given any nonnegative integer n, let g(n) be the sum, over all i
 * in 0..(n-1), of f(i).  This program computes g(n)%10000.
 * The result in an integer in 0..9999.
 * The argument n is specified as the sole argument on the command line.
 * It must be representable as a long int.
 * The program prints the result at the end.
 * Some tests:
 * 1 -> 0
 * 2 -> 7080
 * 100 -> 0076
 *
 * 100000000 takes 4.2 seconds on my MacBook Air
 * 1000000000  takes 43 seconds on same machine
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <mpi.h>
int rank;
int numprocs;
int pin;

int main(int argc, char *argv[]) {
  MPI_Init(&argc, &argv);
  double start_time = MPI_Wtime();
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  assert(argc==2);

  double stop = (double)atol(argv[1]);
  assert(stop >= 1.0);

  int result = 0;

  for (double x = (double)rank; x < stop; x += (double)numprocs) {
    double tmp = sin(x);
    double tmp2 = tmp*tmp;
    int z = (int)(tmp2*10000.0);

    result = (result + z)%10000; // 0<=result<10000
  }
  MPI_Reduce(&result, &pin, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
  pin = pin%10000;
  double finish_time = MPI_Wtime();
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  if(rank == 0){
    printf("The PIN is %d (nprocs = %d, time = %f sec.)\n", pin, numprocs, finish_time-start_time);
  }
  fflush(stdout);
  return 0;
}
