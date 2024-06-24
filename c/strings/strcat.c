#include<stdio.h>

void str_cat(char s[],char d[])
{
	int i,j;
	for(i=0;s[i]!='\0';i++);
	for(j=0;d[j]!='\0';j++,i++)
		s[i] = d[j];
       printf("%s\n",s);	
}
int main()
{
	char s[100],d[100];
	printf("ENter s:");
	scanf("%s",s);
	printf("ENter d:");
        scanf("%s",d);
	str_cat(s,d);
}
