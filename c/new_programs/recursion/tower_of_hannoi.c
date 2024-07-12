#include<stdio.h>
void puzzle(int d)
{
	int src[d],aux[d],dest[d];
	int x=d;
	int top = -1;
	for(int i=0;i<d;i++)
	{
		src[i] = x;
		x--;
		top++;
	}

	int total_moves = (1<< d)-1;

	





	printf("Display:");
	for(int i=0;i<d;i++)
		printf("%d ",dest[i]);
	printf("\n");

}
int main()
{
	int d;
	printf("ENter no.of disks:");
	scanf("%d",&d);
	puzzle(d);

}
