#include <cstdio>
#include <new>
using namespace std;

class c1 {
    int _a = 0;
    int _b = 0;
    int _c = 0;
public:
    c1(int i = 0);
    ~c1();
    int a() { return _a; }
    int b() { return _b; }
    int c() { return _c; }
};

c1::c1(int i) : _a(i), _b(i + 1), _c(i + 2) {
    puts("c1 constructor");
}

c1::~c1() {
    puts("c1 destructor");
}

int main() {
    try {
        c1 * o1 = new c1;
        printf("o1: %d, %d %d\n", o1->a(), o1->b(), o1->c());
        delete o1;
    } catch (std::bad_alloc & ba) {
        printf("new c1 failed: %s\n", ba.what());
        return 1;
    }

    // no throw exception
    c1 * o2 = new(nothrow) c1[5];
    if(o2 == nullptr) {
        puts("new c1 failed");
    }
    printf("o1: %d, %d %d\n", o2->a(), o2->b(), o2->c());
    delete [] o2;
    
    return 0;
}