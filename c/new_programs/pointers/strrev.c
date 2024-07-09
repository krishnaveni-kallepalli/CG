#include<stdio.h>
#include<string.h>
void str_rev(char *s)
{
	char temp;
	char *start = s;
	char *end = s;
	while(*end!='\0') end++;
	end--;
	while(start<end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
        printf("%s\n",s);
}
int main()
{
	char s[100];
	printf("ENter string:");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")]='\0';
	str_rev(s);
}




