//pthread_t threads [NUM_THREADS];

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 5

void *print_hello(void *num) {

	long t_num;
	t_num = (long) num;
	long t_id = pthread_self();
	int i;	
		printf("Thread ID: %ld \n",t_id);

}

int main (int argc, char *argv[]) {

	pthread_t threads [NUM_THREADS];
	int rc;
	int i;
	long t;
	for (t=0; t<NUM_THREADS; t++) {
		printf("In main: creating thread %ld\n",t);
		rc = pthread_create(&threads[t],NULL,print_hello, (void *)t);
		if (rc) {
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit (-1);
		}
		sleep(t);
	}


	for(t = 0; t< NUM_THREADS; t++) {
		pthread_join(threads[t], NULL);
		printf("Thread %ld finished\n",t);
	}
	
	return 0;
}

