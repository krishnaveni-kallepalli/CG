#include<iostream>
using namespace std;
class Base
{
	private:
		int x;
	protected:
		int y;
	public:
		int z;
		Base()
		{
			x=23,y=34,z=78;
		}
};
class Derived : public Base
{
	public:
		void fun()
		{
			cout << x << endl;
			cout << y << endl;
			cout << z << endl;
		}

};
int main()
{
	class Base b;
	class Derived d;
	d.fun();
}
