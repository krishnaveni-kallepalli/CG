#include<iostream>
using namespace std;

class Cons
{
	public:
		Cons()
		{
			cout << "Hello\n";
		}
		Cons(int a,int b)
		{
			cout<< a+b << endl;
		}

		Cons(const Cons &obj)
		{
			cout << "This is cpy cons for obj\n";
		}
		Cons(const Cons &obj,int a,int b)
                {
                        cout << "This is cpy cons for obj1\n";
                        cout << a << endl;
                        cout << b << endl;
                }
};

int main()
{
	class Cons obj;
	class Cons obj1(2,3);

	class Cons x = obj; // method 1
	class Cons y(obj1,4,5); // method 2
	return 0;

}
