#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
void show(const vector<int>& vect)
{
        for(size_t i=0;i<vect.size();i++)
                cout << vect[i] << " ";
        cout <<  endl;
	}
int main()
{
	vector<int> vect;// vect of 10 int elements 
	// adding elements
	cout << "Enter elements:";
	for(size_t i=0;i<10;i++)
	{
		int x;
		cin >>x ;	
		vect.push_back(x);
	}
	// sort
	sort(vect.begin(),vect.end());
	cout << "Sorted elements:\n";
	show(vect);

	vect.pop_back();
	cout << "Deleted last:\n"; 
	show(vect);

	cout << "Insert at 2nd:\n";
	vect.insert(vect.begin()+2,23);
	show(vect);

	cout << "Erase 5th elemnt:\n";
	vect.erase(vect.begin()+5);
	show(vect);

	cout << "First element:\n";
	cout << vect.front() << endl;
	
	cout << "Last element:\n";
	cout << vect.back() << endl;
	
	cout << "Max element:\n";
	cout << "Max:" << max_element(vect.begin(),vect.end()) << endl;

	cout << "Clear all:\n";
	vect.clear();
	if(vect.empty()) cout << "Empty\n";
	show(vect);

	cout << "Resize:\n";
	vect.resize(5);
	cout << vect.size()<< endl;
	show(vect);


	return 0;

}
