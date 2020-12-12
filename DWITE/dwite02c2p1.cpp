/*
DWITE '02 R2 #1 - Sales!
Key Concepts: Implementation
https://dmoj.ca/problem/dwite02c2p1
Solution by Kevin Guo
*/
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>

int main() {
    double x, y, z, a, b, c;
    std::vector<double> output;
    for (int i = 0; i < 5; i++) {
        std::cin >> x >> a >> y >> b >> z >> c;
        a = (x-a)/x*100;
        b = (y-b)/y*100;
        c = (z-c)/z*100;
        output.push_back(std::max(a,std::max(b,c)));
    }
    printf ("%7.3f", output[0]);
    for (int i = 1; i < 5; i++) {
        std::cout << std::endl;
        printf ("%7.3f", output[i]);
    }

    return 0;
}
