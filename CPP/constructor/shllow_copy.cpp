#include<iostream>
using namespace std;

class Shallow
{
	public:
	int *ptr;
	Shallow()
	{
		ptr = new int ;
	}
	void address()
	{
		cout << ptr << endl;
	}

};
class Deep
{
	int *p;
	public:
	Deep(const Deep & obj)
	{
		p = new int;
	}
	void address()
        {
                cout << p << endl;
        }
};
int main()
{
	Shallow s1,s2;
	s1 = s2;
	s1.address();
	s2.address();

	Deep d;
	Deep d1(d),d2(d);
	d1 = d2;
	d1.address();
	d2.address();
}
