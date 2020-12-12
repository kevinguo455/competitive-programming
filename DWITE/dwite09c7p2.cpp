/*
DWITE '09 R7 #2 - Sum of Primes
Key Concepts: Simple Math
https://dmoj.ca/problem/dwite09c7p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
const int MAXN = 100000;
bool isPrime[MAXN];

void sieve() {
    for (int i = 2; i <= sqrt(MAXN); i++) {
        if (isPrime[i]) {
            for (int j = 2*i; j <= MAXN; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    memset(isPrime, 1, sizeof(isPrime)); 
    sieve();
    for (int c=0;c<5;c++) {
        int n; cin>>n;
        ull sum=0;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i])
                sum += i;
        }
        cout << sum << endl;   
    } 
    return 0; 
}