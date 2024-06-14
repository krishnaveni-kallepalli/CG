#include<iostream>
using namespace std;
class Cons
{
	public:
		Cons() {};
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
