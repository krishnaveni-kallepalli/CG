#include<stdio.h>
#include<string.h>
int substring(char s[],char sub[])
{
	int i,j;
	for(i=0;s[i]!='\0';i++)
	{
		for(j=0;sub[j]!='\0';j++)
		{
			if(s[i+j]!=sub[j])
				break;

		}
		if(sub[j]=='\0') return 1;
	}
	return 0;
}
int main()
{
	char s[100],sub[100];
	printf("Enter a string: ");
	fgets(s, sizeof(s), stdin);
        printf("Enter a substring to find: ");
        fgets(sub, sizeof(sub), stdin);
	s[strcspn(s, "\n")] = '\0';
        sub[strcspn(sub, "\n")] = '\0';
	int found = substring(s,sub);
	if(found) printf("Found\n");
	else printf("Not found\n");
}
