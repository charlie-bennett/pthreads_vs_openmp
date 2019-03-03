#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define		num_of_elements	   16*1024*1024
#define NUM_THREADS 2

void quickSort(int* array, int start, int end)
{
	int i = start, j = end;
	int tmp;
	int pivot = array[(start + end) / 2];
	while (i <= j)
	{
		while (array[i] < pivot)  i++;
		while (array[j] > pivot)  j--;
		if (i <= j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++; j--;
		}
	}
	if (start < j)
		quickSort(array, start, j);
	if (i < end)
		quickSort(array, i, end);
}

struct thread_data
{
	void* t_array;
	int t_end;
	int t_start;

}


void* quickSort_thread(int* threadarg)
{
	struct thread_data* my_data;
	my_data = (struct thread_data*) threadarg;
	int my_start = my_data->t_start;
	int my_end = my_data->t_end;
	int* my_array = (int*) my_data->t_array;
	quicksort(my_array, start, end);
	pthread_exit(NULL);

}

int power(int k)
{
	int i, result = 1;
	for (i = 0; i < k; i++)
	{
		result *= 2;
	}
	return result;
}
int main(void)
{
	int i, j, tmp;
	struct timespec start, stop;
	struct  thread_data  thread_data_array[NUM_THREADS];
	pthread_t  threads[NUM_THREADS];
	double exe_time;
	srand(time(NULL));
	int* m = (int*) malloc (sizeof(int) * num_of_elements);
	for (i = 0; i < num_of_elements; i++)
	{
		m[i] = num_of_elements - i;
	}
	if ( clock_gettime(CLOCK_REALTIME, &start) == -1) { perror("clock gettime");}


	////////**********Your code goes here***************//

	i = 0;
	j = num_of_elements - 1;
	int pivot = m[rand() % num_of_elements];
	printf("pivot %d\n", pivot);
	while (i <= j)
	{
		while (m[i] < pivot)  i++;
		while (m[j] > pivot)  j--;
		if (i <= j)
		{
			tmp = m[i];
			m[i] = m[j];
			m[j] = tmp;
			i++;
			j--;
		}
	}

	if (start < j)
		thread_data_array[0].t_array = m;
	thread_data_array[0].t_start = 0;
	thread_data_array[0].t_end = j;
	rc = pthread_create(&threads[0], NULL, quickSort_thread, (void*) &thread_data_array[0]);
	if (rc) { printf("ERROR; return code from pthread_create() is %d\n", rc); exit(-1);}
	if (i < end)
		thread_data_array[1].t_array = m;
	thread_data_array[1].t_start = i;
	thread_data_array[1].t_end = num_of_elements - 1;
	rc = pthread_create(&threads[1], NULL, quickSort_thread, (void*) &thread_data_array[1]);
	if (rc) { printf("ERROR; return code from pthread_create() is %d\n", rc); exit(-1);}


	//printf("i=%d, j=%d\n", i,j);
	//quickSort(m, 0, num_of_elements - 1);
	//quickSort(m, i, num_of_elements-1);
	//quickSort(m, 0, num_of_elements-1);

	///////******************************////
	int ind;
	for (ind = 0; ind < NUM_THREADS; ind++)
	{

		rc = pthread_join(threads[ind], NULL);
		if (rc) { printf("ERROR; return code from pthread_join() is %d\n", rc); exit(-1);}
	}

	if ( clock_gettime( CLOCK_REALTIME, &stop) == -1 ) { perror("clock gettime");}
	exe_time = (stop.tv_sec - start.tv_sec) + (double)(stop.tv_nsec - start.tv_nsec) / 1e9;

	for (i = 0; i < 100; i++) printf("%d ", m[i]);
	printf("\nExecution time = %f sec\n",  exe_time);
}
