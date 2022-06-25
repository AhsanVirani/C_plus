#include <iostream>
using namespace std;

class num {
    int value = 0;
public:
    num( int x = 0 ) : value(x) {}
    int get_value() const { return value; }
    void setvalue( int x ) { value = x; }

    num & operator ++ ();   
    num operator ++ (int);
    num & operator -- ();
    num operator -- (int);
};

// pre increment 
num & num::operator ++ () {
    cout << "pre increment: ";
    value += 1;
    return *this;
}

// post increment
num num::operator ++ (int) {
    cout << "post-increment: ";
    num temp = *this;
    value += 1;
    return temp;
}

// pre increment 
num & num::operator -- () {
    cout << "pre increment: ";
    value -= 1;
    return *this;
}

// post increment
num num::operator -- (int) {
    cout << "post-increment: ";
    num temp = *this;
    value -= 1;
    return temp;
}

ostream & operator << (ostream & o, const num & n) {
    return o << (n.get_value());
}

int main() {
    // prefix
    num a;
    cout << "num is: " << a << endl;
    cout << "num is: " << ++a << endl;

    // postfix
    num b(42);
    cout << "num is: " << b << endl;
    cout << "num is: " << b++ << endl;
    cout << "num is: " << b << endl;

    return 0;
}