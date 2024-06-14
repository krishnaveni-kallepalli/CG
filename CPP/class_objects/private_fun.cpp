#include<iostream>
using namespace std;
class Pfun
{
	void pfun()
	{
		cout << "Private fun()\n";
	}
	void pfun1(int a,int b)
	{
		cout << a+b << endl;
	}
	void pfun2(const Pfun &obj)
	{
		cout << "Just\n";
	}

	public:
	/*
	void fun()
        {
                pfun();
        }
	void fun(int a,int b)
        {
                pfun1(a,b);
        } 
	void fun(Pfun & obj)
        {
                pfun2(obj);
        }*/
	void fun(int a,int b,Pfun & obj)
	{
		pfun();
		pfun1(a,b);
		pfun2(obj);
	}
};

int main()
{
	Pfun p;
//	p.fun(),p.fun(2,3),p.fun(p);
	p.fun(2,3,p);
}

