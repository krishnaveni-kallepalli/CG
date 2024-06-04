#include<iostream>
#include<algorithm>
#include<array>
#include<vector>
#include<list>
using namespace std;

int main()
{
	array<char,5> a;

	vector<int> v;
	list<int> l;
	cout << "ENter elements into array:\n";
	for(int i=0;i<a.size();i++)
	{
		char c;
		cin >> c;
		a[i] = c;
	}
	cout <<"Display:\n";
	for(auto i:a)
	{
		cout << i;
	}

	



}
