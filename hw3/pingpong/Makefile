MPICC = mpicc -pedantic -std=c11
LINKS = -lm

HOST := $(shell hostname)
ifeq ($(HOST),cisc372)
RUN = srun
else
RUN = mpiexec
endif

all : pingpong run

pingpong : pingpong.c
	$(MPICC) -o pingpong pingpong.c $(LINKS)

# Add more rules here for running the MPI version ...

run : pingpong
	$(RUN) -n 20 ./pingpong >ppout.txt

clean :
	rm -f pingpong *~ a.out *.txt
