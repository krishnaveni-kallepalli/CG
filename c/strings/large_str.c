#include<stdio.h>
#include<string.h>
void fun(char s[])
{

	char largest[30];
	int count = 0, max = 0,i,j,index=0,length;
 	length = strlen(s);
 	index=0;
 	for( i = 0 ; i< length ; i++)
 	{
  		if(s[i] != ' ')
   			count++;
  		else
  		{
   			if(count > max)
   			{
    				max = count;
    				index = i-max;
   			}
   			count = 0;
  		}
 	}
 	if(count > max)
 	{
  		max = count;
 	 	index = length-max;
 	}

 	j=0;
 	for(i=index;i<index+max;i++)
 	{
  		largest[j] = s[i];
  		j++;
 	}

 	largest[j] = '\0';
 	printf("Largest substring : %s\n", largest);
 	printf("Length is: %d\n",max);
}
int main()
{
 	char s1[100];
	fgets(s1,sizeof(s1),stdin);
 	s1[strcspn(s1, "\n")] = '\0';	
 	void (*fp)(char []) = fun;
 	fp(s1);
}

