// https://dmoj.ca/problem/ccc03j2
#include <iostream>
#include <math.h>

int main() {

    int n;
    std::cin >> n;
    while (n != 0) {
        int a = floor(sqrt(n));
        while (n % a != 0) {
            a--;
        }
        int b = n / a;
        int p = (a+b) * 2;
        std::cout << "Minimum perimeter is " << p << " with dimensions " << a << " x " << b << std::endl;
        std::cin >> n;
    }
    return 0;
}