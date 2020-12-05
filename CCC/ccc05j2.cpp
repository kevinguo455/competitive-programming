// https://dmoj.ca/problem/ccc05j2
#include <iostream>
#include <math.h>

int main() {

    int lower, upper, rsa = 0;
    std::cin >> lower >> upper;
    int n = lower;

    while (n <= upper) {
        int x = 1, factors = 0;

        while (x <= sqrt(n)) {
            if (x == sqrt(n)) {
                factors++;
            } else if (n % x == 0) {
                factors += 2;
            }
            x++;
        }

        if (factors == 4) {
            rsa++;
        }

        n++;
    }

    std::cout << "The number of RSA numbers between " << lower << " and " << upper << " is " << rsa;

    return 0;
}