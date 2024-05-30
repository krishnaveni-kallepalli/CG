#include<iostream>
#include<queue>

#include<stdlib.h>

#define QUEUE_LIMIT 5
using namespace std;

void display(queue<int> s)
{
	cout << "DISPLAY:\n";
	while(!s.empty())
	{
		cout << s.front() << " ";
		s.pop();
	}
	cout << endl;
}
int main()
{
	queue<int> s;
	int n,op;
	cout << "1.push\n2.pop\n3.display\n";
while(1)
{
	cout << "enter op:";
	cin >> op;
	switch(op)
	{
	case 1:
	if(s.size()<QUEUE_LIMIT)
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
		cout << s.front() << " Deleted\n";
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
