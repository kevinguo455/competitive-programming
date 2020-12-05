// https://dmoj.ca/problem/ccc17s2
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int main() {
    int n, a;
    std::vector<int> v;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> a;
        v.push_back(a);
    }

    std::sort(v.begin(), v.begin()+n);

    int j;
    for (int i = 0; i < n; i++) {
        //start from middle then go to two sides
        if (i % 2 == 0) {
            j = floor((n-1)/2) - ceil(i/2);
        } else {
            j = floor((n-1)/2) + ceil(i/2) + 1;
        }
        std::cout << v[j] << " ";
    }

    return 0;
}