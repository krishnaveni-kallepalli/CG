#include<iostream>
#include<stack>

#include<stdlib.h>

#define STACK_LIMIT 5
using namespace std;

void display(stack<int> s)
{
	cout << "DISPLAY:\n";
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
int main()
{
	stack<int> s;
	int n,op;
	cout << "1.push\n2.pop\n3.display\n";
while(1)
{
	cout << "enter op:";
	cin >> op;
	switch(op)
	{
	case 1:
	if(s.size()<STACK_LIMIT)
	{
		cout << "Enter element:";
		cin >> n;
		s.push(n);	
	}
	else
		cout << "Stack overflow..\n";
	break;
	case 2:
	if(!s.empty())
	{
		cout << s.top() << " Deleted\n";
		s.pop();
	}
	else cout <<"Satck is Empty..\n";
	break;
	case 3:
	display(s);
	break;
	default:exit(0);
	}

}

}
