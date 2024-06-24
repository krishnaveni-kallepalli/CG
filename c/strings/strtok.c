#include<stdio.h>
void word(char w[],int start,int end)
{
	for(int i=start;i<=end;i++)
		printf("%c",w[i]);
	printf("\n");
}
void str_tok(char s[],int len)
{
	int i,start=0;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i] == ' ' || s[i] == '\n' || s[i] =='\0')
		{
			word(s,start,i-1);
			start = i+1;
		}
	}
}
int main()
{
	char s[100];
	printf("Enter string:");
	fgets(s,sizeof(s),stdin);
	int len;
	for(len = 0;s[len]!='\0';len++);
	str_tok(s,len);
	return 0;
}
