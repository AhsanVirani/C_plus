#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char s1[20] = "Good";
	char s2[20] = "Morning";

	// Str cat
	// strcat(s1, s2);

	cout<<s1<<endl;

	// Strlen

	cout<<strlen(s1)<<endl;

	// Str copy

	strcpy(s2, s1);
	cout<<s2<<endl;
}