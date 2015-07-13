//int ret;
//ret = execl ("/bin/vi", "vi", "/home/kidd/hooks.txt", NULL);
//if (ret == –1)
//perror ("execl");

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int fd[2];
	pipe(fd);
	printf("Parrent PID: %d \n",getpid());

	int i;
	int j;
	int stat;
	int exr;

	pid = fork();
	
	switch(pid){

	case -1:
		printf("Error fork\n");
		return -1;

	case 0:
		printf("Child PID after fork: %d\n",getpid());	
		close(fd[0]);
	
		printf("List of tmp folder:\n");
		exr= execl("/bin/ls","ls","-l","/tmp/",NULL);

		return 0;
	default:
		printf("Parrent PID after fork: %d\n", getpid());
		close(fd[1]);
		wait(&stat);
	}
	return 0;
}
