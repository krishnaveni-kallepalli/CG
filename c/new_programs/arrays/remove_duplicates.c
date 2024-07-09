#include<stdio.h>
void remove_dupe(int a[],int n)
{
	int i,j,k,count,max;
	for(i=0;i<n;i++)
	{
		count = 0;
		max = 0;
		for(j=0;j<n;j++)
		{
			if(a[i] == a[j])
			{
				count ++;
				max = j;
			}
		}
		if(count > 1)
		{
			for(k = max;k<n-1;k++)
			{
                        	a[k] = a[k+1];
			}
			n--;
			j--;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");

}
int main()
{
        int n;
        printf("Enter size:");
        scanf("%d",&n);
        int a[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
	remove_dupe(a,n);
	return 0;
}
