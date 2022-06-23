#include <cstdio>
using namespace std;

class A {
    int _value;
public:
    void setv( const int a ) { _value = a; };
    int getv() const { return _value; };
};

int main() {
    A a;
    a.setv(42);
    printf("a is %d\n", a.getv());

    const A b = a;
    printf("b is %d\n", b.getv());
};