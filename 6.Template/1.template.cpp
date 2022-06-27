#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maxof(  T & a, const T & b) {
    return ( a > b?  : b);
}

int main() {
    int a = 7;
    int b = 9;

    float c = 5.4;
    float d = 6.6665;

    cout << "max is " << maxof<int>( a, b ) << endl;
    cout << "max is " << maxof<float>( c, d ) << endl;
}