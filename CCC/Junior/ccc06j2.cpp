// https://dmoj.ca/problem/ccc06j2
#include <iostream>
#include <math.h>

int main() {

    int solutions = 0,a,b;
    std::cin >> a >> b;

    for (int i = a; i > 0; i--) {
        for (int j = b; j > 0; j--) {
            if ((i + j) == 10) {
                solutions++;
            }
        }
    }

    if (solutions == 1) {
        std::cout << "There is 1 way to get the sum 10.";
    }
    else {
        std::cout << "There are " << solutions << " ways to get the sum 10.";
    }

    return 0;
}