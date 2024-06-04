#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<semaphore.h>

int main()
{
	pid_t p1,p2;

	char shared_resource = 'c';

	sem_t sem;
	sem_init(&sem,0,0);

	p1 = fork();
	if(p1==0)
	{
		sem_wait(&sem);
		while(1)
		{
			printf("P1 is using shared resource:%c\n",shared_resource);
			sleep(1);
			sem_post(&sem);
		}
	}
	else
	{
		p2 = fork();
		if(p2==0)
		{
			//printf("P2 is waiting for shared resource.!\n");
			sem_wait(&sem);
       			printf("P2 acquired shared resource.\n");
			sem_post(&sem);
		}
		else
		{
			sleep(1);
			shared_resource = 'r';
			sem_post(&sem);
			wait(NULL);
			wait(NULL);
			printf("Both done ..\n");
		}
	}
	sem_destroy(&sem);
	return 0;

}
