#include<iostream>
using namespace std;
class Cons
{
	public:
		Cons(int a,int b)
		{
			cout  << a+b << endl;
		}
		Cons(string s1, string s2)
		{
			cout << s1+s2 << endl;
		}
};
int main()
{
	int a,b;
	string s1,s2;

	cout << "Enter a,b:";
	cin >> a >> b;

	cout << "ENter s1:";
	cin >> s1;

	cout << "Enter s2:";
	cin >> s2;

	Cons obj1(a,b);
	Cons obj2(s1,s2);
	return 0;
}
