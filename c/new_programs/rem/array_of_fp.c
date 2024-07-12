#include<stdio.h>
void linear(int a[],int n,int key);
void binary(int a[],int n,int key);
void linear(int a[],int n,int key)
{
	int flag = 0,i;
	for(i=0;i<n;i++)
	{
		if(a[i] == key) 
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1) printf("%d found at %d\n",key,i+1);
	else printf("%d not found\n",key);
}
void binary(int a[],int n,int key)
{
	int start = 0;
	int end = n-1;
	int mid;
	while(start<end)
	{
		mid = (start+end)/2;
		if(a[mid] == key) 
		{
			printf("%d found at %d\n",key,mid+1);
			return ;
		}
		if(a[mid] > key)
			end = mid-1;
		if(a[mid] < key)
			start = mid + 1;
	}
}
int main()
{
	int a[100],n,key;
	printf("Enter size:");
	scanf("%d",&n);

	printf("Enter elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);

	printf("Enter element to search:");
		scanf("%d",&key);

//	void (*fp)(int [],int,int) = linear;
//	fp(a,n,key);


	void (*fp[2])(int [],int,int)= {linear,binary};
	for(int i=0;i<2;i++)
		fp[i](a,n,key);

	return 0;
}
