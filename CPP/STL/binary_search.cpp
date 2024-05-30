#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[10];
	int asize = sizeof(a)/sizeof(a[0]);
	for(int i;i<asize;i++)
		cin >> a[i];
	cout << "asize:" << asize;
	sort(a,a+asize);
	int x;
	cout << "Enter x:";
	cin >> x;
	if(binary_search(a,a+asize,x))
		cout << x << " is found\n";
	else
		cout << x << " is not found\n";
}
