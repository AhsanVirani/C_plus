#include <iostream>
using namespace std;

class Base {
public:
	Base(){cout<<"Non-param Base"<<endl;}
	Base(int x){cout<<"Non-param Base "<<x<<endl;}
};

class Derived:public Base {
public:
	Derived(){cout<<"Non-param Derived"<<endl;}
	Derived(int y){cout<<"Non-param Derived"<<y<<endl;}
	Derived(int x, int y):Base(x) {
		cout<<"Param of Derived "<<y<<endl;
	}
};

int main() {
	Derived d;
	Derived e(5, 10);

	
	return 0;
};