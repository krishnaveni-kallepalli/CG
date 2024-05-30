#include<iostream>
#include<array>
#include<algorithm>
using namespace std;
template<size_t size>
void disp(array<int,size>& arr)
{
	 cout << "Display:\n";
        for(auto i :arr)
                cout << i << " " ;
        cout << endl;
}
int main()
{
	array<int,10> a;
	array<int,10> b;

	cout << "Enter array elements:\n";
	for(auto i=0;i<a.size();i++)
		cin >> a[i];

	disp(a);
	

	cout << a.at(2) << endl;
	cout << get<0>(a) << endl;
	cout << "Front:" << a.front() << endl;
	cout << "back:" << a.back() << endl;
	cout << "Size:" << a.size() << endl;
	cout << "Max size:" << a.max_size() << endl;

	cout << "Enter array elements:\n";
        for(auto i=0;i<b.size();i++)
                cin >> b[i];

 	disp(b);

	a.swap(b);

        cout << "Front:" << b.front() << endl;
        cout << "back:" << b.back() << endl;
        cout << "Size:" << b.size() << endl;
        cout << "Max size:" << b.max_size() << endl;

	a.fill(0);
	cout << (a.empty()?"Empty\n":"Not empty\n");

	array<int,0> ar;
	cout << (ar.empty()?"Empty\n":"Not empty\n");

	return 0;

}
