/*
Facebook Hacker Cup 2015 Round 1 Problem 1 - Homework
Key Concepts: Prime Sieve, Prefix Sum Array
https://dmoj.ca/problem/fhc15c1p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7+5, MAXK = 9; 

int sieve[MAXN];
int psa[MAXN][MAXK];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 2; i < MAXN; i++) {
        if (sieve[i] == 0) {
            for (int j = i; j < MAXN; j += i) {
                sieve[j]++;
            }
        }
    }
    for (int i = 2; i < MAXN; i++) {
        for (int j = 0; j < MAXK; j++) psa[i][j] += psa[i-1][j];
        psa[i][sieve[i]-1]++;
    }

    int cases; cin >> cases;
    for (int i = 1, a, b, k; i <= cases; i++) {
        cin >> a >> b >> k;
        cout << "Case #" << i << ": " << psa[b][k-1] - psa[a-1][k-1] << '\n';
    }

    return 0;
}