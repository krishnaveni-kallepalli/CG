#include<stdio.h>
#include<string.h>
void find_replace(char s[],char sub[],char new[])
{
	int i,j,k,found=0;
	int slen = strlen(s);
    	int sublen = strlen(sub);
    	int newlen = strlen(new);
	for(i=0;s[i]!='\0';i++)
	{
		for(j=0;sub[j]!='\0';j++)
		{
			if(s[i+j]!=sub[j])
				break;
		}
		if(j==sublen)
		{
			found =1;
			for(k=0;k<newlen;k++)
				s[i+k] = new[k];
			for(k=i+newlen;k<=slen;k++)
				s[k] = s[k + sublen -newlen];
			slen = slen - sublen + newlen;
			i+=newlen-1;
		}
	}
	if(found==1) printf("%s\n",s);
	else printf("%s not found\n",sub);
}
int main()
{
	char s[100],sub[100],new[100];
	printf("s:");
	fgets(s,sizeof(s),stdin);
	printf("sub:");
        fgets(sub,sizeof(sub),stdin);
	printf("new:");
        fgets(new,sizeof(new),stdin);
	s[strcspn(s,"\n")] = '\0';
	sub[strcspn(sub,"\n")] = '\0';
	new[strcspn(new,"\n")] = '\0';
	find_replace(s,sub,new);
}
