#include<stdio.h>
void string_rev(char s[],int i,int j)
{
	if(i>j) return ;
	s[i] = s[i]+s[j]-(s[j] = s[i]);
	string_rev(s,i+1,j-1);
}
int main()
{
	char s[10];
	int n;
	printf("Enter n:");
	scanf("%d",&n);
	printf("Enter string:");
	scanf("%s",s);
	string_rev(s,0,n-1);
	printf("%s\n",s);


}
