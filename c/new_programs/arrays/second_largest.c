#include<stdio.h>
int second_largest(int a[],int n)
{
	int fl=a[0],sl=a[1];
	if(a[0]<a[1])
	{
		fl = a[1];
		sl = a[0];
	}
	for(int i=2;i<n;i++)
	{
		if(a[i] > fl)
		{
			sl = fl;
			fl = a[i];
		}
	}
	return sl;

}
int main()
{
        int n;
        printf("Enter size:");
        scanf("%d",&n);
        int a[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("Second largest : %d\n",second_largest(a,n));
	return 0;
}
