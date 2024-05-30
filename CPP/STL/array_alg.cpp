#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
int main()
{
	int a[10];
	cout << "Enter elements:";
	for(int i=0;i<10;i++)
		cin >> a[i];
	int asize = sizeof(a)/sizeof(a[0]);

	// all_of positive/not
	all_of(a,a+asize,[](int x){ return x>0;})? cout << "all positive\n" : cout << "Negative exists\n";

	//any_of -ve / not 
	any_of(a,a+asize,[](int x) { return x<0; })? cout << "Nagative exists\n":cout << "all positive\n"; 

	//none_of
	none_of(a,a+asize,[](int x) { return x<0; })? cout << "No nagative exists\n":cout << "negative exists\n";
}
