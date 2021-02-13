// https://dmoj.ca/problem/ccc96s1
#include <iostream>
#include <math.h>
#include <vector>

int d(int n) {
    std::vector<int> s;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            s.push_back(i);
        }
    }
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        //std::cout << s[i] << " ";
        sum += s[i];
    }

    return sum;
}

int main() {
    int n, x, s;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        s = d(x);
        //std::cout << s << std::endl;
        if (s == x) {
            std::cout << x << " is a perfect number.";
        }
        else if (s < x) {
            std::cout << x << " is a deficient number.";
        }
        else {
            std::cout << x << " is an abundant number.";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
