#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define INTERVALS 5000000000L

int rank;
int numprocs;
long double pi;

int main(int argc, char *argv[]) {    
  long double area = 0.0;
  long double xi;
  long i;

  MPI_Init(&argc, &argv);
  double start_time = MPI_Wtime();
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  for (i=(long)rank; i<INTERVALS; i+=(long)numprocs) {
    xi=(1.0L/INTERVALS)*(i+0.5L);
    area += 4.0L/(INTERVALS*(1.0L+xi*xi));
  }
  MPI_Reduce(&area, &pi, 1, MPI_LONG_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); 
  double finish_time = MPI_Wtime();
  MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  if(rank == 0){
	printf("Pi is %20.17Lf (nprocs = %d, time = %f sec.)\n", pi, numprocs, finish_time-start_time);
  }
  fflush(stdout);
  return 0;
}
