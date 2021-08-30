#include <iostream>

using namespace std;

enum day {mon, tues, wed, thur, fri, sat, sun};

typedef int marks;

int main() {
	
	day d;
	d=tues;

	cout<<d<<endl;

	marks m1 = 90;
	marks m2 = 50;
	marks m3 = 60;

	cout<<m1<<" "<<m2<<" "<<m3<<endl;

}