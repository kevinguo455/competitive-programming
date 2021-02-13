// https://dmoj.ca/problem/ccc17j2
#include <iostream>
#include <math.h>

int main() {
    int n, k, x = 0;
    std::cin >> n >> k;

    while (k >= 0) {
        x += n * pow(10,k);
        k--;
    }

    std::cout << x;

    return 0;
}