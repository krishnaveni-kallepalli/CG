#include<stdio.h>
#include<string.h>
void tok(char s[])
{
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i+1] == ' ')
			s[i+1] = '\n';
	}
	printf("%s\n",s);
}
int main()
{
	char s[100];
	printf("ENter string:");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")]='\0';
	str_tok(s);
}




