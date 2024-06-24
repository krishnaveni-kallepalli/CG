#include<stdio.h>
void str_rev(char s[],int i,int j)
{
	if(i>j) return;
	s[i] = s[i]+s[j]-(s[j] = s[i]);
	return str_rev(s,i+1,j-1);

}
void word(char w[],int start,int end)
{
	for(;start<end;start++,end--)
		w[start] = w[start]+w[end]-(w[end] = w[start]);
}
void rev_word(char s[],int len)
{
	int i,start=0;
	for(i=0;i<=len;i++)
	{
		if(s[i] == ' ' || s[i] == '\n'|| s[i] == '\0')
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
	for(len=0;s[len]!='\0';len++);
	str_rev(s,0,len-1);
	rev_word(s,len);
	printf("%s\n",s);
}

