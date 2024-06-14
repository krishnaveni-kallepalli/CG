#include<iostream>
using namespace std;
class Cons
{
	Cons()
	{
		cout << "private constrictor\n";
	}
	Cons(int a,int b)
	{
		cout << a+b << endl;
	}
	Cons(const Cons &obj)
	{
		cout << "Cpy - default private constructor\n";
	}
	Cons(const Cons &obj,int a,int b)
	{
		cout << "Cpy - private param constructor\n";
		cout << a+b << endl;
	}

	public:

	static Cons fun()
	{
		return 	Cons();
	}
	static Cons fun1(int a, int b)
	{
		return Cons(a,b);
	}
	static Cons fun2(Cons & obj)
	{
		return Cons(obj);
	}
	static Cons fun3(Cons &obj,int a,int b)
	{
		return Cons(obj,a,b);
	}

};
int main()
{
	Cons a = Cons :: fun();
	Cons b = Cons :: fun1(2,3);
	Cons c = Cons :: fun2(a);
	Cons d = Cons :: fun3(b,4,5);

	return 0;

}
