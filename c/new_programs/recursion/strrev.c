#include<stdio.h>
#include<string.h>

void rev(char s[],int i,int j)
{
	if(i>=j) return ;
	s[i] = s[i] + s[j] - (s[j] = s[i]);
	return rev(s,i+1,j-1);
}
int main()
{
	char s[100];
	printf("Enter string:");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")] = '\0';
	int len  = strlen(s);
	rev(s,0,len-1);
	printf("After reversal:%s\n",s);

}
