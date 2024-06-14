#include<iostream>
using namespace std;
class Cons
{
	public:
		Cons()
		{
			cout << "This is constructor\n";
		}
		void fun()
		{
			cout << "hey\n";
		}
};
int main()
{
	class Cons c;
	c.fun();
}
