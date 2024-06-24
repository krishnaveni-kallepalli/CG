#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void len_fgets(char s[])
{
	int i;
        for(i=0;s[i]!='\0';i++)
        {
                if(s[i] == '\n')
                {
                        s[i] = '\0';
                        break;
                }
        }
        printf("Strlen:%d\n",i);
}
int main()
{
	char s[100];
	printf("Enter string:");
	gets(s);
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i] == '\n')
		{
			s[i] = '\0';
			break;
		}
	}
	printf("Strlen:%d\n",i);
}
