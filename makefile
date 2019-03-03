CC = gcc
CFLAGS += -O3
LFLAGS +=  -lpthread
LFLAGS += -fopenmp

all: 
	gcc -O3 -o p1_omp p1_omp.c -fopenmp
	gcc -O3 -o p2_pthread p2_pthread.c -lpthread

1: p1_omp
	gcc -O3 -o p1_omp p1_omp.c -fopenmp

2: p2_pthread
	gcc -O3 -o p2_pthread p2_pthread.c -lpthread

run1: p1_omp
	srun -n1 -c8 ./p1_omp
run2: p2_pthread
	srun -n1 -c8 ./p2_pthread
run_all: problem2a problem2b
	srun -n1 -c8 ./p1_omp
	srun -n1 -c8 ./p2_pthread


clean: 
	$(RM) p1_omp p2_pthread 1 