#include <cstdio>

// // C macro definition. Not a const
// #define ONE 1
// #define HELLO "Hello, World!"

// C++ replacement as const
constexpr const int ONE = 1;
constexpr const char * HELLO = "Hello, World!";

int main() {
    // printf("%s %d\n", HELLO, ONE);
    printf("%s %d\n", HELLO, ONE);
    return 0;
}