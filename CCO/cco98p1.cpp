/*
CCO '98 P1 - Fibonacci Numbers
Key Concepts: Implementation
https://dmoj.ca/problem/cco98p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201; 

struct BigNum {
    vector<short> digits; // reversed order
    void operator=(int n) {
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }    
    }
    void operator=(BigNum b) {
        digits = b.digits;
    }
    BigNum operator+(BigNum b) {
        BigNum res;
        res.digits.resize(max(digits.size(), b.digits.size()));
        for (int i = 0; i < max(digits.size(), b.digits.size()); i++) {
            if (i < digits.size()) res.digits[i] += digits[i];
            if (i < b.digits.size()) res.digits[i] += b.digits[i];
            if (res.digits[i] >= 10) {
                res.digits[i] -= 10;
                if (i+1 == res.digits.size()) res.digits.push_back(1);
                else res.digits[i+1]++;
            }
        }
        return res;
    }
    void print() {
        for (int i = digits.size()-1; i >= 0; i--) cout << digits[i];
        cout << '\n';
    }
};

BigNum fib[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i < MAXN; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    int n; cin >> n;
    while (n != 0) {
        fib[n].print();
        cin >> n;
    }

    return 0;
}