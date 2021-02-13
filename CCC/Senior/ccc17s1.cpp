// https://dmoj.ca/problem/ccc17s1
#include <iostream>
#include <vector>

int main() {
    int n, a, m = 0, ta = 0, tb = 0;
    std::vector<int> va;
    std::vector<int> vb;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> a;
        va.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        std::cin >> a;
        vb.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        ta += va[i];
        tb += vb[i];
        if (ta == tb) {
            m = i + 1;
        }
    }

    std::cout << m;

    return 0;
}
