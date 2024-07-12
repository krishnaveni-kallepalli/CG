#include<stdio.h>
#include<string.h>
int pal_rec(char s[],int i,int j)
{
	if(i>=j) return 1;
	if(s[i] == s[j]) 
		pal_rec(s,i+1,j-1);
	else return 0;
}
int main()
{
	char s[100];
	printf("Enter str:");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")] = '\0';
	int len = strlen(s);
	int x = pal_rec(s,0,len-1);

	if(x == 0) printf("not palindrome\n");
	else printf("plaindrome\n");
}
