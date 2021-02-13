// https://dmoj.ca/problem/ccc04j2
#include <iostream>

int main() {
    int a, b, n = 0;
    std::cin >> a >> b;
    while (a <= b) {
        std::cout << "All positions change in year " << a << std::endl;
        a += 60;
    }
    return 0;
}