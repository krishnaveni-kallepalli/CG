#include<stdio.h>
#include<math.h>
void qrd(int a,int b,int c)
{
	int sq = sqrt(pow(b,2) - (4*a*c));
	int res = (-b+sq)/(2*a);
	printf("%f\n",res);
}
int main()
{
	int a,b,c;
	printf("Enter a,b,c:");
	scanf("%d %d %d\n",&a,&b,&c);
	qrd(a,b,c);
	return 0;

}
