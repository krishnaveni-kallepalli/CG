#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void *print_msg(void *ptr)
{
	printf("%s\n",(char *)ptr);
}
void fun(char ch)
{
	printf("%c\n",ch);
}

int main()
{
	pthread_t t1,t2;
	char m1[10] = "hello";
	char m2[10] = "hie";

	for(int i=0;i<10;i++)
	{
		pthread_create(&t1,NULL,print_msg,&m1),sleep(2);
		char ch = getchar();
		if(ch>='a' && ch<='z')
			fun(ch);
		pthread_create(&t2,NULL,print_msg,&m2),sleep(1);
	}
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;

}
