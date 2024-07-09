#include<stdio.h>
#include<stdlib.h>

struct student
{
	int age;
	char name[50];
	int ID;
};

int main()
{
	struct student stu;
	struct student *p;
	p = &stu;


	printf("Enter name:");
	scanf("%s",p->name);

	printf("Enter age:");
	scanf("%d",&p->age);

	printf("Enter ID:");
	scanf("%d",&p->ID);

	printf("Name:%s\n",p->name);
	printf("ID:%d\n",p->ID);
	printf("Age:%d\n",p->age);
	return 0;

}
