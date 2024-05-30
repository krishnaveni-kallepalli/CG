#include<iostream>
#include<list>
#iinclude<algorithm>
using namespace std;
void show(list<int>& l)
{
	for(auto i : l)
        	cout << i << " ";
    	cout << endl;
}
int main()
{
	list<int> l;
	l={1,2,3,4};
	for(auto i : l)
		cout << i << " " ;
	cout << endl;

	cout << "front:" << l.front() << endl;
        cout << "back:" << l.back() << endl;

	cout <<"Push:\n";
	l.push_front(23);
	l.push_back(23);
	show(l);
	cout << "Pop:\n";
	l.pop_front();
	l.pop_back();
	show(l);
	cout << "Insert:\n";
	auto it = l.begin();
	advance(it,4);
	l.insert(it,88);
	show(l);

	cout << "Size:" << l.size() << endl;

	cout << "Max element:\n";
	auto x = max_element(l.begin(),l.end());
	if(x!= l.end())
		cout << *x <<  endl;

}
