
/*create pipe
make fork
close deskriptor

child
close exit desk
read in

PID
информация из 
*/
#include <stdio.h>
#include <unistd.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2

int sum;

void *print_hello (void *num)
{
long t_num;
t_num=(long) num;
int i;
long int id;
/*for(i=0;i<10;i++)
{
	id=(long int)pthread_self();
	printf("ID: %ld\n",t_num);
	printf("Hello World! Thread num: %ld\n", id);
	sleep(1);
	}*/
}

void *plus(void *num)
{
	sum=sum+5;
}

void *minus(void *num)
{
	sum=sum-3;
}

int main(int argc, char *argv[])
{
pthread_t threads[NUM_THREADS];
sum=20;
int rc;
long t;
printf("Number before threads: %d \n",sum);
t=0;
printf("IN main:creating thread %ld\n",t);
rc=pthread_create(&threads[t],NULL,plus, (void *) t);
	
t=1;
printf("IN main:creating thread %ld\n",t);
rc=pthread_create(&threads[t],NULL,minus, (void *) t);

for (t=0;t<NUM_THREADS;t++){
	pthread_join (threads[t], NULL);
	printf("thread #%ld finished\n", t);
}
printf("Number after threads: %d \n",sum);
return 0;

}
