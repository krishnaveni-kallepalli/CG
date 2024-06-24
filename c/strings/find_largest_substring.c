#include<stdio.h>
#include<string.h>
void count(char s[],int len,int a[])
{
 
        for(i=0;i<len;i++)
        {
                if(s[i] == ' ' || s[i] == '\0')
                {
                       	
                }
        }

}

int main()
{
	char s[100];
        int len,a[10]={0};
        printf("Enter string:");
        fgets(s,sizeof(s),stdin);
        s[strcspn(s, "\n")] = '\0';
        for(len=0;s[len]!='\0';len++);
}

