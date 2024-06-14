#include<iostream>
using namespace std;
class Deep
{
	int x;
	int *p;
	public:
	Deep()
	{
		p=new int;
	}
	Deep(const Deep & obj)
	{
		p = new int;
		*p = *(obj.p);
	}
	void address()
        {
		cout << &x << endl;
                cout << p << endl;
        }
	~Deep()
	{
		delete p;
	}
};
int main()
{
	Deep d;
	Deep d1(d),d2(d);
	d1 = d2;
	d1.address();
	d2.address();
}
