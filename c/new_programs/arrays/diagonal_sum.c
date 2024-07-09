#include<stdio.h>
int diagonal_sum(int a[][10],int n)
{
        int sum = 0;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
		{
			if(i == j)
			{
				printf("a[i][]:%d\n",a[i][j]);
				sum = sum + a[i][j];
			}
		}
        }
        return sum;
}
int main()
{
        int n;
        printf("Enter size:");
        scanf("%d",&n);
        int a[n][n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
                	scanf("%d",&a[i][j]);
        printf("Array elements are:\n");
	for(int i=0;i<n;i++)
	{
		printf("[ ");
		for(int j=0;j<n;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("]\n");
	}
	printf("Sum of all diagonal elements :%d\n",diagonal_sum(a,n));
        return 0;
}
