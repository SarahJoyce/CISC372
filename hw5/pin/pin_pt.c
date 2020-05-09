/* 
 * MPI:
 * sjoyce@cisc372:~/372-homework/hw3/pin$ srun -n 40 ./pin_mpi 100000000
 * The PIN is 6586 (nprocs = 40, time = 0.141926 sec.)
 *
 * PThreads:
 * sjoyce@cisc372:~/372-homework/hw5/pin$ srun -c 40 ./pin_pt 100000000 40
 * The PIN is 6586 (nthreads = 40, time = 5.910381 sec.)
 * 
 * The runtimes for both programs were very similar each time (MPI about 0.14 seconds,
 * PThreads about 5.8 seconds). The MPI Version was faster.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

void * pin(void *rank);

int nthreads;
double stop;
int result;

int main(int argc, char *argv[]) {
  assert(argc==3);
  nthreads = (int)atoi(argv[2]);
  stop = (double)atol(argv[1]);
  assert(stop >= 1.0);

  result = 0;
  clock_t start_time = clock();

  pthread_t *threads = (pthread_t *)malloc(nthreads * sizeof(pthread_t));
  for (long int tid = 0; tid < nthreads; tid++){
    pthread_create(&threads[tid], NULL, pin, (void *)tid);
  }

  for (long int tid = 0; tid < nthreads; tid++){
    pthread_join(threads[tid], NULL);
  }

  result = result % 10000;

  clock_t end_time = clock();
  double time = (double)(end_time-start_time)/(CLOCKS_PER_SEC);

  printf("The PIN is %d (nthreads = %d, time = %f sec.)\n", result, nthreads, time); 
  fflush(stdout);
  return 0;
}

void * pin(void *rank){
  long int tid = (long int) rank;
  
  int local_result = 0;
  for(int x=tid; x<stop; x+=nthreads){
    double tmp = sin(x);
    double tmp2 = tmp*tmp;
    int z = (int)(tmp2*10000.0);
    local_result = (local_result + z) % 10000;
  }
  result += local_result;
}

