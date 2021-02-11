/*
DMOPC '19 Contest 6 P2 - Grade 10 Math
Key Concepts: Simple Math (prime factorization)
https://dmoj.ca/problem/dmopc19c6p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

vector<int> primes;
bitset<MAXN> sieve;

void find_primes() {
    sieve.set();
    for (int i = 2; i < MAXN; i++) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = i+i; j < MAXN; j += i) {
                sieve[j] = 0;
            }
        }   
    }
}

unordered_map<int, int> prime_factor(int n) {
    unordered_map<int, int> out;
    for (int p : primes) {
        while (n % p == 0) {
            n /= p;
            out[p]++;
        }
    }
    return out;
}

int count(int p, int n) {
    int a = p, res = 0;
    while (a <= n) {
        res += n/a;
        a *= p;
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    find_primes();

    int a, b; cin >> a >> b;
    int ans = 0x3f3f3f3f;
    unordered_map<int, int> factorization = prime_factor(a);
    for (pair<int, int> p : factorization) {    
        ans = min(ans, count(p.first, b) / p.second);
    }
    cout << ans << '\n';

    return 0;
}