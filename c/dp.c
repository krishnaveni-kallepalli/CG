#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=10;
	int *p1;
       p1=  &a;
	int **p2 = &p1  ; 
	    printf("%d",**p2);
	printf("%d",*p1);	
}
