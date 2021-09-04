#include <iostream>
#include <cstring>

using namespace std;

int main() {

	string str = "today";
	string::iterator it;

	for(it=str.begin(); it!=str.end();it++){
		cout<<*it;
	}
	cout<<endl;
}