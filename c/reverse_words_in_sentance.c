#include <stdio.h>
#include <string.h>

void rev(char s[],int i, int j)
{
        if(i>j) return;
        s[i] = s[i]+s[j]-(s[j]=s[i]);
        return rev(s,i+1,j-1);
}
void rev_word(char w[],int start,int end)
{
	for(;start<end;start++,end--)
		w[start] = w[start]+w[end]-(w[end] = w[start]);	
}
void word_rev(char s[], int n) {
    int start = 0;
    for(int i = 0; i <= n; i++) {
        if(s[i] == ' ' || s[i] == '\0') {
            rev_word(s,start,i-1);
            start = i + 1;
        }
    }
}
int main() {
    char s[100]="hello world";
    int n = strlen(s);
    rev(s,0,n-1);
    word_rev(s, n);
    printf("%s\n", s);
    return 0;
}

