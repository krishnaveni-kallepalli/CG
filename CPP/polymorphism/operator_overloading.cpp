#include<iostream>
using namespace std;
class Overload
{
	int a,b,c;
	public:
	Overload()	
	{
		a=2;
		b=3;
		c=5;
	}
	Overload(int x, int y, int z) : a(x),b(y),c(z){}
	Overload operator +(const Overload &obj)
	{
		return Overload(a+obj.a,b+obj.b,c+obj.c);
	}
	Overload operator -()
	{
		return Overload(-a,-b,-c);
	}
	void disp()
	{
		cout << a << " ";
		cout << b << " ";
		cout << c << " ";
		cout << endl;
	}
};
int main()
{
	Overload o1,o2(1,1,1);
	Overload o3 = -o1;
	Overload o4 = o1+o2;
	o3.disp();
	o4.disp();
}
