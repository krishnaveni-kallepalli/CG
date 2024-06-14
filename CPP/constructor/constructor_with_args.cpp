#include<iostream>
using namespace std;

class Cons
{
	public:
		Cons()
		{
			cout << "Hello\n";
		}
		Cons(int a,int b)
		{
			cout<< a+b;
		}
};

int main()
{
	class Cons obj;
	class Cons obj1(2,3);

}
