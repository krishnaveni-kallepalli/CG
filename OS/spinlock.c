#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main()
{
	pid_t p1,p2;
	char shared_resource = 'c';
	p1 = fork();
	if(p1==0)
	{
		while(1)
		{
			printf("P1 is using shared resource:%c\n",shared_resource);
		}
	}
	else
	{
		p2 = fork();
		if(p2==0)
		{
			printf("P2 is waiting for shared resource.!\n");
			char ch = getchar();
			while (shared_resource != 'r') {
                // Busy wait
            }
            printf("P2 acquired shared resource.\n");
		}
		else
		{
			wait(NULL);
			wait(NULL);
			printf("Both done ..\n");
		}
	}
	return 0;

}
