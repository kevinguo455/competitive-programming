/*
CCO '17 P1 - Vera and Trail Building
Key Concepts: Graph Theory (components)
https://dmoj.ca/problem/cco17p1
Solution by Kevin Guo
*/

#include <iostream>

int largestTriIndex(int n) {
    int i = 1;
    while (((i+1) * (i+2)) / 2 <= n) {
        i++;
    }
    return i;
}

int main() {
    int n, m, a = 0, x, y = -1, z = 0;
    std::cin >> n;

    x = n;
    while (x > 0) {
        m = largestTriIndex(x);
        x -= m * (m+1)/2;
        y += m + 2;
        z += m + 1;
    }

    std::cout << z << " " << y;

    while (n > 0) {
        m = largestTriIndex(n);
        //std::cout << m << " " << std::endl;
        n -= m * (m+1)/2;

        for (int i = 0; i < m; i++) {
            std::cout << std::endl << i + a + 1 << " " << i + a + 2;
        }
        std::cout << std::endl << a + m + 1 << " " << a + 1;
        if (a != 0) {
            std::cout << std::endl << a << " " << a + 1;
        }
        a += m + 1;
    }

    return 0;
}