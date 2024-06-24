#include<stdio.h>
#include<string.h>
void largest(char s[])
{
	int slen = strlen(s);
	int i,j,max=0,count=0,max_start = 0,start = 0;
	for(i=0;i<=slen;i++)
	{
		count++;
		if(s[i]==' ' || s[i]=='\0')
		{
			count = 0;
			start = i+1;
		}
		if(count > max)
		{
			max = count;
			max_start = start;
		}

	}
	for(i=max_start;i<=max_start+max-1;i++)
		printf("%c",s[i]);
	printf("\nLength:%d\n",max);
}
int main()
{
	char s[100] ;
	printf("Enter s:");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")] = '\0';
	largest(s);
}



