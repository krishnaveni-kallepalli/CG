#include<stdio.h>

int smallest_int(int a[],int n)
{
        int small = a[0];
        for(int i=1;i<n;i++)
        {
                if(a[i] < small)
                        small = a[i];
        }
        return small;
}
int main()
{
        int n;
        printf("Enter size:");
        scanf("%d",&n);
        int a[n];
        printf("Enter elements:\n");
        for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
        printf("Smallest element: %d\n",smallest_int(a,n));
        return 0;
}
