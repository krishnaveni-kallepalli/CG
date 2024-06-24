#include<stdio.h>
#include<string.h>
int word(char w[],int start,int end)
{
	int count = 1,large=0;
	while(start!=end)
	{
		start++;
		 count++;
	}
	return count;	

}
void count(char s[],int len,int a[])
{
	int start=0,i,index=0;
	for(i=0;i<=len;i++)
	{
		if(s[i] == ' ' || s[i] == '\0')
		{
			a[index++] = word(s,start,i-1);
			start = i+1;
		}
	}
	
}
int main()
{
	char s[100];
	int len,a[10]={0};
	printf("Enter string:");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s, "\n")] = '\0';
	for(len=0;s[len]!='\0';len++);
	count(s,len,a);
	for(int i=0;i<10 && a[i]!=0;i++)
		printf("%d ",a[i]);
	return 0;
}
