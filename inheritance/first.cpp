#include <iostream>
using namespace std;

class Base {
public:
	void display() {
		cout<<"Displace of Base"<<endl;
	};
};

class Derived:public Base {
public:
	void show() {
		cout<<"Show of Derived"<<endl;
	}
};

int main() {
	Base b;
	b.display();

	Derived d;
	d.display();
	d.show();
}