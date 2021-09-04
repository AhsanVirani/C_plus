#include <iostream>

using namespace std;

int main() {

	int A[10] = {2, 4, 6, 8, 5, 9, 10};

	int sum = 0;
	for(auto x: A)  
		sum+=x;

	cout<<"Sum of all elements is "<<sum<<endl;

	return 0;
}