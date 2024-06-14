#include<iostream>
using namespace std;
class Overload
{
	public:
	int fun(int a,int b)
	{
		return a+b;
	}
	string fun(string s1,string s2)
	{
		return s1+s2;
	}
};
int main()
{
	Overload obj;
	int a,b;
	string s1,s2;
	cout << "ENter a,b:";
	cin >> a >> b;

	cout << obj.fun(a,b) << endl;

	cout << "Enter s1:";
	cin >> s1;
	cout << "Enter s2:";
	cin >> s2;
	
	cout << obj.fun(s1,s2) << endl;
}
