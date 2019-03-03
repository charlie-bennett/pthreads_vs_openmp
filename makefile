CC = gcc
CFLAGS += -O3
LFLAGS +=  -lpthread
LFLAGS += -fopenmp

all: 
	gcc -O3 -o problem2a problem2a.c -fopenmp
	gcc -O3 -o problem2b problem2b.c -lpthread

1: problem2a
	gcc -O3 -o problem2a problem2a.c -fopenmp

2: problem2b
	gcc -O3 -o problem2b problem2b.c -lpthread

run_2a: problem2a
	srun -n1 ./problem2a 
run_2b: problem2b
	srun -n1 ./problem2b
run_all: problem2a problem2b
	srun -n1 -c8 ./problem2a
	srun -n1 -c8 ./problem2b


clean: 
	$(RM) problem2a problem2b 1 