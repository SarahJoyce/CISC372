#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#define NPINGS 1000000

int rank;
int numprocs;
int msg1, msg2;

int main(int argc, char *argv[]) {    
  double start_time;
  double finish_time;
  double total_time;
  MPI_Init(&argc, &argv);
  MPI_Status status;
  //MPI_Barrier(MPI_COMM_WORLD);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

  if(rank==0){
    for(int j = 1; j<numprocs; j++){
	start_time = MPI_Wtime();
	for (int i=1; i<NPINGS; i++) {
	    MPI_Send(&msg1, 0, MPI_INT, j, 99, MPI_COMM_WORLD);
	    MPI_Recv(&msg2, 0, MPI_INT, j, 99, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
 	}
     finish_time = MPI_Wtime();
     total_time = (finish_time-start_time)/(2*NPINGS);
     printf("Average time to trasmit between 0 and %d: %11.10f\n", j, total_time);
    }
  }else{
    for(int j = 1; j<numprocs; j++){
	for (int i=1; i<NPINGS; i++) {
	    MPI_Recv(&msg2, 0, MPI_INT, 0, 99, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	    MPI_Send(&msg1, 0, MPI_INT, 0, 99, MPI_COMM_WORLD);
	}
    }	
  }
  //MPI_Barrier(MPI_COMM_WORLD);
  MPI_Finalize();
  fflush(stdout);
  return 0;
}
