#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

struct res 
{
	char a[10];
	char b[10];
};
int main()
{
	pid_t p1,p2;
	p1 = fork();
	struct res *r;
	r = (struct res*)malloc(sizeof(struct res));	

	strcpy(r->a,"hello");
	strcpy(r->b,"hie");
	if(p1==0)
	{
		printf("P1 is using a,%s\n",r->a);
		while((strcmp(r->b,"available"))!=0)
		{
			sleep(10);
			if(strcmp(r->b,"available"))
					printf("B is released by p2:%s\n",r->b);
		}
		exit(0);
	}
	else
	{
		p2 = fork();
		if(p2==0)
		{
			printf("p2 is using b,%s\n",r->b);
			while((strcmp(r->a,"available"))!=0)
			{
				sleep(10);
				if(strcmp(r->a,"available"))
					printf("A is released by p1:%s\n",r->a);
			}
			exit(0);
                }
		else 
		{
			wait(NULL);
			wait(NULL);
			printf("Both completed..\n");
		}
	}

	free(r);
	return 0;
}
