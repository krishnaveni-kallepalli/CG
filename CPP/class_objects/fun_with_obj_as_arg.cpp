#include<iostream>
using namespace std;
class Fun
{
	int x=33,y=35;

	public:
	 Fun()
        {
                x=23;
                y=34;
	}       
	void fun1()
	{
		cout << x << y << endl;
	}	
		void fun(Fun &obj)
		{
			cout << obj.x  << obj.y << endl;
			cout << x << y << endl;
		}

};
int main()
{
	Fun f;
	f.fun1();
	f.fun(f);
}
