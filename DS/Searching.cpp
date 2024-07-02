#include<iostream>
using namespace std;

class Search
{
	int a[10];
	int x;
	public:
	int size;
	void set();
	void init();	
	void linear_search();
	void binary_search(int,int);
	void Bin(int,int);
};
void Search :: set()
{
	cout << "Enter size:";
	cin >> size;
	cout << "Enter elements:\n";
	for(int i=0;i<size;i++)
		cin >> a[i];
}
void Search :: init()
{
	cout << "Enter x:";
	cin  >> x;
}
void Search :: linear_search()
{
	int flag=0,i;
	for(i=0;i<size;i++)
	{
		if(a[i] == x) 
		{
			flag = 1; 
			break;
		}
	}
	if(flag ==1) cout << x << " found at " << i+1 << " position\n";
	else cout << x << " not found in array\n";
}
void Search :: binary_search(int start,int end)
{
	int i,flag =0,mid;
	for(i=start;i<=end;i++)
	{
		mid  = start+(end - start) / 2;;
		if(a[mid] > x) end = mid-1;
		else if(a[mid] < x) start = mid+1;
		else if(a[mid] == x)
		{
			flag = 1;
			break;
		}
	}
	if(flag ==1) cout << x << " found at " << mid+1 << " position\n";
        else cout << x << " not found in array\n";
}
void Search :: Bin(int start,int end)
{
        int i,flag =0,mid;
	mid  = (start+end)/2;
	if(a[mid]> x) Bin(start,mid-1);
        else if(a[mid] < x) Bin(mid+1,end);
        else if(a[mid] == x)
        {
               cout << x << " found at " << mid+1 << " position\n";
               return ;
        }
	else cout << x << " not found in array\n";

}
int main()
{
	class Search s;
	int ch;
	cout << "\n1.Linear Search\n2.Binary Search\n3.Binary Recursion\n\n";
	cout << "Enter choice:";
	cin >> ch;
	switch(ch)
	{
		case 1 : 
			s.set();
        		s.init();
        		s.linear_search();
			break;
		case 2:
			s.set();
        		s.init();
        		s.binary_search(0,s.size-1);
			break;
		case 3 :
			s.set();
			s.init();
			 s.Bin(0,s.size-1);
			 break;
		default: cout << "Invalid..\n";
	}
	return 0;
}
