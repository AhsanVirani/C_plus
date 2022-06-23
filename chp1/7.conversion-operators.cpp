#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class Rational {
    int _n = 0;
    int _d = 1;
public:
    Rational ( int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator) {};
    Rational ( const Rational & rhs) : _n(rhs._n), _d(rhs._d) {};   // copy constructor
    ~Rational();
    
    int numerator() const { return _n; };
    int denominator() const { return _d; };

    // operators
    Rational & operator = ( const Rational & );
    Rational operator + ( const Rational & ) const;
    Rational operator - ( const Rational & ) const; 
    Rational operator * ( const Rational & ) const; 
    Rational operator / ( const Rational & ) const; 
    operator std::string () const;

};

Rational & Rational::operator = ( const Rational & rhs ) {
    if( this != &rhs ) {
        _n = rhs.numerator();
        _d = rhs.denominator();
    }
    return *this;
}

Rational Rational::operator + ( const Rational & rhs ) const {
    return Rational((_n * rhs._d) + (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator - ( const Rational & rhs ) const {
    return Rational ((_n * rhs._d) - (_d * rhs._n), _d * rhs._d);
}

Rational Rational::operator * ( const Rational & rhs ) const {
    return Rational ((_n * rhs._n), (_d * rhs._d));
}

Rational::operator std::string() const {
    if( _d == 1 ) return std::to_string(_n);
    else return std::to_string(_n) + "/" + std::to_string(_d);
}


Rational::~Rational() {
    _n = 0; _d = 1;
}

// for std::cout
std::ostream & operator << (std::ostream & o, const Rational & r) {
    if(r.denominator() == 1) return o << r.numerator();
    else return o << r.numerator() << '/' << r.denominator();
}

int main() {
    const Rational a = 7;
    cout << "a is: " << a << endl;
    Rational b(5, 3);
    cout << "b is: " << b << endl;
    Rational c = b; // copy constructor
    cout << "c is: " << c << endl;
    Rational d;     // default constructor
    cout << "d is: " << d << endl;
    d = c;          // assignment operator
    cout << "d is: " << d << endl;
    Rational & e = d;   // reference
    cout << "e is: " << e << endl;

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    string x = "Hello, World!";
    cout << x << endl;
    x += b; // x = x + b -> 
    cout << x << endl;
}
