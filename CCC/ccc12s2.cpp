// https://dmoj.ca/problem/ccc12s2
#include <iostream>
#include <string>

int c(char r) {
    if (r == 'M') {
        return 1000;
    }
    else if (r == 'D') {
        return 500;
    }
    else if (r == 'C') {
        return 100;
    }
    else if (r == 'L') {
        return 50;
    }
    else if (r == 'X') {
        return 10;
    }
    else if (r == 'V') {
        return 5;
    }
    else if (r == 'I') {
        return 1;
    }
    return 0;
}

int main() {
    std::string str;
    std::cin >> str;
    int n = 0;
    int v, w = 0;
    for (int i = str.length()-1; i >= 0; i -= 2) {
        v = c(str[i]);
        if (v < w) {
            n -= v*(str[i-1] - '0');
        }
        else {
            n += v*(str[i-1] - '0');
        }
        w = v;
    }
    std::cout << n;
    return 0;
}