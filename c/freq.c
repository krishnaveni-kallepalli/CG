#include<stdio.h>
int main()
{
	char s[10] = "hello";
	//char alp[30] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int i,j,k;
	for(i=0;s[i]!='\0';i++)
	{
		int count = 0;
		int duplicate = 0;
	        for(j=0;s[j]!='\0';j++)
		       if(alp[i] == s[j]) count ++,duplicate=1;      
	   	if(count!= 0) printf("%c:%d\n",alp[i],count);
	}
}
