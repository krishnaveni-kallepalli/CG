#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *print_msg(void *ptr)
{
	printf("%s\n",(char *)ptr);
}

void *disp_msg(void *ptr)
{
	printf("this is Disp_msg fun..\n");
	printf("%s\n",(char *)ptr);
}

int main()
{
	pthread_t t1,t2;
	char m1[10] = "hello";
	char m2[10] = "hie";

	for(int i=0;i<10;i++)
	{
		pthread_create(&t1,NULL,print_msg,&m1);
		pthread_create(&t2,NULL,disp_msg,&m1),sleep(1);
	}
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;

}
