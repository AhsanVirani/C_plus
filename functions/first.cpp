#include <iostream>
using namespace std;

int sum(int a, int b){
	return a+b;
}

float sum(float a, float b){
	return a+b;
}

int main() {

	int a = 5;
	int b= 3;

	cout<<sum(a, b)<<endl;

	float c = 2.2;
	float d = 5.4354;
	cout<<sum(c, d)<<endl;

	return 0;
}
