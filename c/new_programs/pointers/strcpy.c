#include<stdio.h>
#include<string.h>
void str_cpy(char *d,const char *s)
{
	for(int i=0;*s!='\0';i++)
	{
		*d = *s;
		d++;
		s++;
	}
	*d='\0';
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
	str_cpy(d,s);
	printf("s:%s\n",s);
	printf("d:%s\n",d);

}
