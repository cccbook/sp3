#include <stdio.h>

#define _assert(cond) if (!cond) printf("Assertion (" #cond ") fail!\nFile: %s, Line %d\n", __FILE__, __LINE__);

int main() {
    _assert(1==0);
}
