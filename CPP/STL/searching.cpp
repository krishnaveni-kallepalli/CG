#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;
void show(vector<int>& vect)
{
	for(int i=0;i<vect.size();i++)
		cout << vect[i] << " ";
	cout <<  endl;
}
int main()
{
	vector<int> vect;
	cout << "Enter elements into vector:\n";
	for(int i=0;i<5;i++)
	{
		int x;
		cin >> x;
		vect.push_back(x);
	}

	show(vect);
	cout <<"Find element in vector:\n";
	int x;
	cout << "Enter element to search:";
	cin >> x;
	// find pos of x 
	//  distance(vect.begin(),find(vect.begin(),vect.end(),x)

	if(find(vect.begin(),vect.end(),x) != vect.end()) 
		cout << "Found at " << distance(vect.begin(),find(vect.begin(),vect.end(),x));
	else cout << "not found\n";

	return 0;

}
