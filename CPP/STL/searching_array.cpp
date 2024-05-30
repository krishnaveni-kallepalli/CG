#include<iostream>
#include<numeric>
#include<algorithm>

using namespace std;
int main()
{
	int a[10];
	for(int i=0;i<10;i++)
		cin >> a[i];
	int asize = sizeof(a)/sizeof(a[0]);
	int x;
	cout << "Enter element to search:";
	cin >> x;
	auto find_x = find(begin(a),end(a),x);
        int pos_x = distance(begin(a),find(begin(a),end(a),x));	
	if(find_x != end(a)) 
		cout << "Found at " << pos_x+1;
	else cout << "Not found\n";


		


}
