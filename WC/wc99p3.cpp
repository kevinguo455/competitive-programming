/*
WC '99 P3 - The Godfather
Key Concepts: Implementation
https://dmoj.ca/problem/wc99p3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int POINTS = 30000; 

double L;

struct Point {
    double x, y;
    void randomize() {
        x = (double) rand() / RAND_MAX * L;
        y = (double) rand() / RAND_MAX;
    }
    bool under_curve() {
        return y <= exp(-(x*x));
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> L;
    Point p;
    while (L != -1) {
        int count = 0;
        for (int i = 0; i < POINTS; i++) {
            p.randomize();
            if (p.under_curve()) count++;
        }
        cout << (double) count / POINTS * L << '\n';
        cin >> L;
    }

    return 0;
}