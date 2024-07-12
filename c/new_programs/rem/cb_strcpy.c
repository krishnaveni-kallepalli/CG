#include<stdio.h>
#include<string.h>
char s[100],d[100];
void cb_input(void (*fp)(char [],char []))
{
	printf("ENter str:");
	fgets(s,sizeof(s),stdin);
	s[strcspn(s,"\n")] = '\0';
}
void str_cpy(char d[],char s[])
{
	int i;
	for(i=0;s[i]!='\0';i++)
		d[i] = s[i];	
	d[i] = '\0';
}
void cb_output(void (*fp)(char [],char []))
{
	printf("s:%s\n",s);
        printf("d:%s\n",d);
}
int main()
{
	void (*fp)(char [],char []) = str_cpy;
	cb_input(fp);
	cb_output(fp);
	return 0;
}
