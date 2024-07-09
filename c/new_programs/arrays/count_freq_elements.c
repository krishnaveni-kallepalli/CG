#include<stdio.h>
#define MAX_INT 9999
void find_occurance(int a[],int n)
{
	int i,j,count;
	for(i=0;i<MAX_INT;i++)
	{
		count = 0;
		for(j=0;j<n;j++)
		{
			if(a[j] == i) count ++;
		}
		if(count>0) printf("%d occured %d times\n",i,count);
	}
}
int main()
{
	int n;
	printf("ENter size:");
	scanf("%d",&n);
	int a[100];
	printf("Enter elements into array:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	find_occurance(a,n);
	return 0;
}

