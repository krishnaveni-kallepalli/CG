#include<iostream>
#include<algorithm>
#include<numeric>
using namespace std;
// accumulate -> sum, prodeuct of all elements in array 
// custom lambda fun -> finds max of two
int main()
{
	int a[10] = {1,2,4,4,5,4,2,3,2,0};
	int asize = sizeof(a)/sizeof(a[10]);
	int add;
	add=accumulate(a,a+asize,0);
	cout <<"sum of all elements:" << add << endl;
	int prod;
	prod = accumulate(a,a+asize,1,multiplies<int>());
	cout << "product of all emenents:" << prod << endl;
	int cl = accumulate(a,a+asize,a[0],[](int x, int y) {return max(x,y);});
        cout << "Max of all:" << cl << endl;	
}
