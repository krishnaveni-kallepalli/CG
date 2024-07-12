#include<stdio.h>

void func(void (*fp)())
{
	fp();
	printf("Hie\n");
}
void fun()
{
	printf("Hello\n");
}


int main()
{
	void (*fp)() = fun;
	func(fp);
	return 0;
}
