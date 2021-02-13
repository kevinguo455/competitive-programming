/*
CCC '07 J3 - Deal or No Deal Calculator
Key Concepts: Implementation
https://dmoj.ca/problem/ccc07j3
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define fio cin.tie(0)->sync_with_stdio(0)
const int MAXN = 10; 

int values[MAXN] = {100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};

int main() {
    fio;

    int sum = 0;
    for (int i = 0; i < MAXN; i++) sum += values[i];

    int n, x; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum -= values[x-1];
    }

    cin >> x;
    cout << (x > sum / (MAXN-n) ? "deal" : "no deal") << "\n";
    
    return 0;
}