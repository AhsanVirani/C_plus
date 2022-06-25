#include <iostream>
#include <string>
#include <memory>
#include "strc.h"

void message(const char * s) {
    printf("\n%s\n", s);
    fflush(stdout);
}

// display object value from shared_ptr (with ref count)
void disp(const std::shared_ptr<strc> & o) {
    if(o) printf("%s (%ld)\n", o->value(), o.use_count());
    else puts("[null]");
    fflush(stdout);
}

// display object value from shared_ptr (with ref count)
void disp(const std::weak_ptr<strc> & o) {
    size_t count = o.use_count();   // weak pointer count
    if(auto sp = o.lock())  printf("%s (w:%ld s:%ld)", sp->value(), count, sp.use_count());
    else puts("[null]");
    fflush(stdout);
}

int main() {
    message("create shared pointer");
    auto a = std::make_shared<strc>("one");
    
    message("make several copies");
    auto c1 = a;
    auto c2 = a;
    auto c3 = a;
    auto c4 = a;

    message("reference count is now 6");
    disp(a);

    message("create weak_ptr");
    auto w1 = std::weak_ptr<strc>(a);
    disp(w1);

    message("destroy copies");
    c1.reset();
    c2.reset();
    c3.reset();
    c4.reset();

    message("reference count should be 1");
    disp(a);

    message("check weak pointer");
    disp(w1);

    message("end of scope");
}