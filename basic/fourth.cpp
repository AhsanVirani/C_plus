#include <iostream>
using namespace std;

int main() {

	string str;

	cout<<"What's your name\n";
	getline(cin, str);

	cout<<"Hello "<<str<<endl;

	return 0;
}