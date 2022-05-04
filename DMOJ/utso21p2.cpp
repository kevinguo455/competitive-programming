/*
UTS Open '21 P2 - Prime Array
Key Concepts: Ad Hoc
https://dmoj.ca/problem/utso21p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+5; 

int rect[MAXN];
bool sieve[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (int i = 1; i < 100; i++) {
        rect[i*(i+1)/2] = i;
    }
    rect[MAXN-1] = 100;
    for (int i = MAXN-2; i > 0; i--) {
        if (rect[i] == 0) rect[i] = rect[i+1];
    }

    memset(sieve, 1, sizeof sieve);
    for (int i = 2; i < sqrt(MAXN); i++) {
        for (int j = i+i; j < MAXN; j += i) {
            sieve[j] = 0;
        }
    }

    vector<int> p;
    for (int i = 2; i < MAXN; i++) {
        if (sieve[i]) p.push_back(i);
    }

    int K; cin >> K;
    if (K == 0) {
        cout << "1\n2\n";
        return 0;
    }    

    int N = rect[K];
    cout << N << '\n';
    
    int d = N*(N+1)/2 - K;
    for (int i = 0; i < d; i++) cout << p[i] << ' ';
    for (int i = d; i < N; i++) cout << "1 ";
    cout << '\n';

    return 0;
}