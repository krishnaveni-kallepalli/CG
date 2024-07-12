#include<stdio.h>
#include<stdbool.h>
bool binary_rec(int a[],int start,int end,int key)
{
	if(start>end) return false;
	int mid = start + (end - start) / 2;
	if(a[mid] == key)
		return true;
	if(a[mid] > key)
		binary_rec(a,start,mid-1,key);
	if(a[mid] < key)
		binary_rec(a,mid+1,end,key);

}
void binary_search(int a[],int n,int key)
{
	int i,j;
	int start = 0,end = n-1,mid;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(a[mid] == key)
		{
			printf("%d is Found\n",key);
			return ;
		}
		if(a[mid] > key)
			end = mid-1;
		if(a[mid] < key)
			start = mid+1;
	}
	printf("%d not Found\n",key);
}
int main()
{
	int a[100],n,key;
	printf("Enter size:");
	scanf("%d",&n);

	printf("Enter elements:\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("ENter element to search:");
	scanf("%d",&key);
	binary_search(a,n,key);

	int res = binary_rec(a,0,n-1,key);
	if(res) printf("%d is Found\n",key);
	else printf("%d not Found\n",key);

}
