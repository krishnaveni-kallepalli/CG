#include<stdio.h>
#include<string.h>
void str_str(char s[],char sub[])
{
	int slen = strlen(s);
	int sublen = strlen(sub);
	for(i=0;i<slen;i++)
	{
		for(j=0;j<sublen;j++)
		{
			if(s[i] == s[j])
			{
				i++;
				j++;
			}
		}
	}
	
}
int main()
{
	char s[100],sub[10];

	printf("Enter s:");
	scanf("%s",s);
	printf("Enter sub:");
	scanf("%s",sub);

	str_str(s,sub);
	return 0;
}
