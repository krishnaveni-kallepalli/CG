#include<stdio.h>
#include<string.h>
int str_len(const char *s)
{
	int len = 0;
	while(*s!='\0')
	{
		len++;
		s++;
	}
	return len;
}
int main()
{
	char s[100];
	printf("ENter string:");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")]='\0';
	printf("String Length:%d\n",str_len(s));
}
