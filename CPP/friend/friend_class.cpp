#include<iostream>
using namespace std;
class Hello
{
	public:
	int a,b,c;
	Hello():a(23),b(33),c(43) {};
	friend class Hey;

};
class Hey
{
	public:
	void fun(Hello &obj)
	{
		cout << obj.a << endl;
		cout << obj.b << endl;
		cout << obj.c << endl;
	}
};
int main()
{
	Hello obj;
	Hey h;
	h.fun(obj);

}
