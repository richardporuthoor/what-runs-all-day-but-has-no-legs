#include <iostream>
#include "src/timer.hpp"

int main() {
    Timer a;
    Timer b;

    a.set_elapsed_seconds(62);    // 1 min 2 sec
    b.set_elapsed_seconds(125);   // 2 min 5 sec

    Timer sum = a.add(b);         // 187 sec
    Timer diff = a.subtract(b);   // 0 sec (because negative becomes 0)

    sum.pretty_print();
    diff.pretty_print();

    return 0;
}