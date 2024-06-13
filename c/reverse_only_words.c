#include<stdio.h>
void rev_word(char w[],int start, int end)
{
	for(;start<end;start++,end--)
		w[start] = w[start]+w[end]-(w[end] = w[start]);
}

void fun(char s[],int n)
{
	int start = 0;
	for(int i=0;i<=n;i++)
	{
		if(s[i] == ' ' || s[i] == '\0')
		{
			rev_word(s,start,i-1);
			start = i+1;
		}
	}
}

int main()
{
	char s[100] = "hello everybody";
	int n;
	for(n=0;s[n]!='\0';n++);

	fun(s,n);
	printf("%s",s);
	return 0;
}

