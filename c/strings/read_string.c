#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char s[100];
	printf("ENter s:");
	scanf("%s",s);
	printf("%s\n",s);
	fgets(s,sizeof(s),stdin);
	printf("%s\n",s);
	gets(s);
	printf("%s\n",s);
	char *str;
	size_t buff_size=0;
	getline(str,&buff_size,stdin);

	printf("str:%s\n",str);

	
}
