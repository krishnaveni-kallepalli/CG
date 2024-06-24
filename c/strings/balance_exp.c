#include<stdio.h>
int chk_balance(char s[],int len)
{
	int i,top=-1;
	char stk[100];
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i] == '{' || s[i] == '[' || s[i] == '(')
		{
			top++;
			stk[top] = s[i];
		}
		else if(s[i] == '}' || s[i] == ']' || s[i] == ')')
		{
			if(top == -1) return -1;
			else if(s[i] == '}' && stk[top]!='{' ||
				s[i] == ']' && stk[top]!='[' || 
				s[i] == ')' && stk[top]!='(')
			{
				return -1;
			}
			top--;
		}
		
	}
	return (top == -1);
}
int main()
{
	char s[100];
	printf("ENter string:");
	scanf("%s",s);
	int len;
	for(len=0;s[len]!='\0';len++);
	if(chk_balance(s,len)==1) printf("Balanced\n");
        else printf("not balanced\n");
}
