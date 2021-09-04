// Templating

#include <iostream>
using namespace std;

// Generics

template<class T>
T maxim(T a, T b){
	return a>b?a:b;
}

int main(void){
	cout<<maxim(5, 15)<<endl;
	cout<<maxim(5.675, 14.333)<<endl;

	return 0;
}