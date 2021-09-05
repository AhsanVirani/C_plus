#include <iostream>
using namespace std;

class Rectangle{
private:
	int length;
	int breadth;
public:
	// Constructor
	Rectangle(int l, int b){
		setLength(l);
		setBreadth(b);
	}

	void setLength(int l){
		length=l;
	}
	void setBreadth(int b){
		breadth=b;
	}
	int area(){
		return length*breadth;
	}
	int perimeter(){
		return 2*(length+breadth);
	}
};

int main(void) {
	// Working in Stack
	Rectangle r1(10, 15);

	cout<<r1.area()<<endl;
	cout<<r1.perimeter()<<endl;

	return 0;
}