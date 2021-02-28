/*
UTS Open '21 P1 - COVID Party
Key Concepts: Binary Search
https://dmoj.ca/problem/utso21p1
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5; 

int capacity(int n) {
    if (n % 2 == 0) return (n/2) * n;
    return (n/2 + 1) * (n/2 + 1) + (n/2) * (n/2);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    int l = 0, r = 1e5+1, m;

    while (l != r) {
        m = (l+r)/2;
        if (capacity(m) > N) {
            r = m;
        }
        else if (capacity(m) < N) {
            l = m+1;
        }
        else {
            l = m;
            break;
        }
    }

    cout << l-1 << '\n';

    return 0;
}