#include<iostream>
#include<numeric>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int a[10];
	cout << "Enter elements into array:\n";
	for(int i=0;i<10;i++)
		cin >>a[i];
	int asize = sizeof(a)/sizeof(a[0]);

	auto max = max_element(a,a+asize);
	if(max != a+asize)
		cout << "Max:" << *max << endl;	




	vector<int> vect;
	cout << "Enter elements into vector:\n";
	for(int i=0;i<10;i++)
	{
		int x;
		cin >> x;
		vect.push_back(x);
	}
	

	auto max_vect = max_element(vect.begin(),vect.end());
	if(max_vect != vect.end())
		cout << "Max: " << *max_vect << endl;

}
