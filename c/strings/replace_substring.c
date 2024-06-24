#include<stdio.h>
#include<string.h>
void replace_substring(char s[],char sub[],char news[])
{
	int i,j,k,found;
	int slen=strlen(s);
	int sublen = strlen(sub);
	int newlen= strlen(news);
	for(i=0;s[i]!='\0';i++)
	{
		for(j=0;sub[j]!='\0';j++)
		{
			if(s[i+j]!=sub[j])
				break;

		}
		if(j==sublen)
		{
			
			for(k=0;k<newlen;k++)
				s[i+k] = news[k];
			for(k=i+newlen;k<=slen;k++)
				s[k] = s[k + sublen - newlen];
			slen = slen - sublen + newlen;
			i+=newlen-1;
		}
	}
	if(found==1) printf("%s\n",s);
	else printf("cannot replace.. %s not found\n",sub);
}
int main()
{
	char s[100],sub[100],news[100];

	printf("Enter a string: ");
	fgets(s, sizeof(s), stdin);
        printf("Enter a substring to find: ");
        fgets(sub, sizeof(sub), stdin);
	printf("Enter a replacement string: ");
        fgets(news, sizeof(news), stdin);
	s[strcspn(s, "\n")] = '\0';
        sub[strcspn(sub, "\n")] = '\0';
	news[strcspn(news, "\n")] = '\0';

	replace_substring(s,sub,news);
	
}
