#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define NPINGS 1000000

int rank;
int numprocs;

int main(int argc, char *argv[]) {  
  double start_time, finish_time, total_time;	
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Barrier(MPI_COMM_WORLD);

  for(int i=1; i<numprocs; i++){
    if(rank == 0){
	start_time = MPI_Wtime();
	for(int j=0; j<NPINGS; j++){
	  MPI_Send(NULL, 0, MPI_CHAR, i, 99, MPI_COMM_WORLD);
	  MPI_Recv(NULL, 0, MPI_CHAR, i, 99, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	}
    }else if(rank == i){
	for(int j=0; j<NPINGS; j++){
	  MPI_Recv(NULL, 0, MPI_CHAR, 0, 99, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	  MPI_Send(NULL, 0, MPI_CHAR, 0, 99, MPI_COMM_WORLD);
	}
    }
    finish_time = MPI_Wtime();
    total_time = (finish_time-start_time)/(2*NPINGS);
    MPI_Barrier(MPI_COMM_WORLD);
     if(rank == 0){
	printf("Average time to transmit between 0 and %d: %11.10f\n", i, total_time);
	fflush(stdout);
     }
  }
  MPI_Finalize();
  return 0;
}
