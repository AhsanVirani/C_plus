#include <iostream>
using namespace std;

template<typename T>
T pi = T(3.142353453534342342L);

template<typename T>
T area_of_circle(const T & r) {
    return r * r * pi<T>;
}


int main() {
    cout.precision(20);
    cout << pi<int> << endl;
    cout << area_of_circle<long double>(6.543) << endl;
}