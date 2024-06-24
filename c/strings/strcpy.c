#include<stdio.h>
void str_cpy(char d[],char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i] =='\n')
		{
			s[i] = '\0';
			break;
		}
		d[i] = s[i];
	}
	d[i] ='\0';
	printf("Dest:%s\n",d);

}
int main()
{
	char s[100],d[100];
	printf("Enter source:");
	fgets(s,sizeof(s),stdin);
	printf("Enter dest:");
	fgets(d,sizeof(s),stdin);
	str_cpy(d,s);

}
