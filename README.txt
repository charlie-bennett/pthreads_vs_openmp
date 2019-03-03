Charles Bennett
PA3
USC ID: 8311964095

README: 

TORUN: 

$make all
$make run_all

//To run one part at a time

	gcc -O3 -o p1_omp p1_omp.c -fopenmp
	gcc -O3 -o p2_pthread p2_pthread.c -lpthread
	srun -n1 -c8 ./p1_omp
	srun -n1 -c8 ./p2_pthread


Results: 






PTHREADS:

---------- Begin SLURM Prolog ----------
Job ID:        2815953
Username:      cfbennet
Accountname:   lc_xq
Name:          p2_pthread
Partition:     quick
Nodelist:      hpc0971
TasksPerNode:  1
CPUsPerTask:   8
TMPDIR:        /tmp/2815953.quick
SCRATCHDIR:    /staging/scratch/2815953
Cluster:       uschpc
HSDA Account:  false
---------- 2019-03-02 18:41:04 ---------
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
Execution time = 0.451256 sec
srun: error: hpc0971: task 0: Exited with exit code 31
cfbennet@hpc-login3:~/PA3$ 






OPENMP:


---------- Begin SLURM Prolog ----------
Job ID:        2815634
Username:      cfbennet
Accountname:   lc_xq
Name:          run
Partition:     quick
Nodelist:      hpc0972
TasksPerNode:  1
CPUsPerTask:   8
TMPDIR:        /tmp/2815634.quick
SCRATCHDIR:    /staging/scratch/2815634
Cluster:       uschpc
HSDA Account:  false
---------- 2019-03-02 16:27:29 ---------
Estimated pi is 3.142402, execution time = 0.106126 sec
 With 1 threads 
Estimated pi is 3.141314, execution time = 0.083743 sec
 With 2 threads 
Estimated pi is 3.141278, execution time = 0.064457 sec
 With 4 threads 
srun: error: hpc0972: task 0: Exited with exit code 73