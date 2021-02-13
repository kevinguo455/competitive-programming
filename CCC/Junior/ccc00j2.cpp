// https://dmoj.ca/problem/ccc00j2
#include <iostream>
#include <math.h>

int length(int n) {
    int i = 1;
    while (n >= 10) {
        n = floor(n/10);
        i++;
    }
    return i;
}

int getDigit(int n, int d) {
    for (int i = 1; i < d; i++) {
        n = floor(n/10);
    }
    return n % 10;
}

bool isRotatable(int n) {
    int l = length(n);
    if (l % 2 == 1) {
        int m = getDigit(n,(l+1)/2);
        if (m != 1 && m != 0 && m != 8) {
            return false;
        }
    }
    int a, b;
    for (int i = 1; i <= floor(l/2); i++) {
        a = getDigit(n, i);
        b = getDigit(n, l-i+1);
        if ((a == 1 && b == 1) || (a == 0 && b == 0) || (a == 8 && b == 8) || (a == 9 && b == 6) || (a == 6 && b == 9)) {
            //Good
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    int a, b, n = 0;
    std::cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (isRotatable(i) == true) {
            n++;
        }
    }
    std::cout << n;
    return 0;
}