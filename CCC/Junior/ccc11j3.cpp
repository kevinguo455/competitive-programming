// https://dmoj.ca/problem/ccc11j3
#include <iostream>
#include <math.h>

int main() {

    int a, b, c, length = 2;
    std::cin >> a >> b;

    if (a == 0 && b == 0) {std::cout << 2;}
    else {

    int difference = a - b;

    while (difference >= 0) {
        a = b;
        b = difference;
        difference = a - b;
        length++;
    }

    std::cout << length; }
    return 0;
}