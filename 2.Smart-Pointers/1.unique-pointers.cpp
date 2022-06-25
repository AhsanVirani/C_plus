#include <iostream>
#include <cstdio>
#include <memory>
#include <utility>
#include "strc.h"

using namespace std;

void message(const char * s) {
    printf("\n%s\n", s);
    fflush(stdout);
}

// display object value from unique_ptr
void disp(unique_ptr<strc> & o) {
    if(o) puts(o->value());
    else puts("null");
    fflush(stdout);
}

int main() {

    message("create unique pointer one");
    unique_ptr<strc> a(new strc("one"));
    disp(a);

    message("make unique two");
    auto b = make_unique<strc>("two");
    disp(a);
    disp(b);

    printf("\n");
    message("setting data under a to data under b");
    *(a) = *(b);
    disp(a);
    disp(b);

    message("reset a to three");
    a.reset(new strc("three"));
    disp(a);
    disp(b);

    cout << "Operator const char *" << (const char * )*(a)  << endl;
    const char * x = (const char * )*(a);
    cout << x << endl;

    message("move b to c");
    auto c = move(b);
    disp(a);
    disp(b);
    disp(c);

    message("reset a");
    a.reset();
    disp(a);
    disp(b);

    message("release c");
    c.release();
    disp(a);
    disp(b);
    disp(c);

    message("end of scope");

    return 0;
}