#include<stdio.h>
#include<string.h>
int main()
{
	char s[100] = "abc1def1";

	for(int i=0;i<strlen(s);i++)
	{
		if(s[i] == 49)
			s[i] = 48;
	}
printf("%s",s);
}
