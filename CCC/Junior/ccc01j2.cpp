// https://dmoj.ca/problem/ccc01j2
#include <iostream>
#include <math.h>

int main() {
    int x, m;
    std::cin >> x >> m;
    for (int i = 0; i < m; i++) {
        if (x*i % m == 1) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << "No such integer exists.";
    return 0;
}