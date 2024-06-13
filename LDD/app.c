#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *p[10]={"hi","hello"};
	for(int i=0;i<2;i++)
	{
		printf("%s",p[i]);
	}
}

