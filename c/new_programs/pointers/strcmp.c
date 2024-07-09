#include<stdio.h>
#include<string.h>
void str_cmp(char *d,const char *s)
{
	int flag = 0;
	while(*s!='\0' && *d!='\0')
	{
		if(*s!=*d)
		{
			flag = 1;
			break;
		}
		s++;
		d++;
	}
	if(flag == 0 && *s=='\0' && *d == '\0') printf("same\n");
	else printf("different\n");
}
int main()
{
	char s[100],d[100];
	printf("Enter s,d:");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")]='\0';
	fgets(d,sizeof(d),stdin);
	d[strcspn(d,"\n")]='\0';
	printf("s:%s\n",s);
        printf("d:%s\n",d);
	str_cmp(d,s);
}
