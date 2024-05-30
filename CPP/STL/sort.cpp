#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[] = {5,4,6,2,5,1,7};
	int b[] = {1,2,3,8,6,3,9,1};
	int bsize = sizeof(b)/sizeof(b[0]);
	sort(begin(a),end(a));
	cout << "a:\n";
	for(int i:a)
		cout << i << " ";
	cout << endl;
	cout << "b:\n";
	sort(b,b+bsize);
	for(int i :b)
		cout << i << " ";
	cout << endl;


}
