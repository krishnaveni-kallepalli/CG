#include <stdio.h>
#include <string.h>
int str_spn(char str1[],char str2[])
{
	int i,j;
	for(i=0,j=0;str1[i]!='\0' && str2[j]!='\0' && str1[i] != str2[j];i++,j++);
	return i;
}

int main() {
    char str1[100];
    char str2[100]; 
    printf("Enter str1,str2:");
    scanf("%s %s",str1,str2);
    size_t len = str_spn(str1, str2);
    printf("%ld\n",len); 
    return 0;
}

