// https://dmoj.ca/problem/ccc02s2
#include <iostream>
#include <math.h>

int relativelyPrime(int a, int b) {
    for (int i = 2; i <= a; i++) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a, b, d, w = 0;
    std::cin >> a >> b;
    if (a == 0) {
        std::cout << 0;
        return 0;
    }
    while (a >= b) {
        a -= b;
        w++;
    }
    d = relativelyPrime(a,b);
    while (d != -1) {
        a /= d;
        b /= d;
        d = relativelyPrime(a,b);
    }
    if (w != 0) {
        std::cout << w << " ";
    }
    if (a != 0) {
        std::cout << a << "/" << b;
    }

    return 0;
}
