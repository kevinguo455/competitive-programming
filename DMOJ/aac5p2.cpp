/*
An Animal Contest 5 P2 - Permutations & Products
Key Concepts: Implementation, Ad Hoc
https://dmoj.ca/problem/aac5p2
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5+5; 

ll prod[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    ll m = 0x3f3f3f3f3f3f3f3f, t = 0;
    for (int i = 2; i <= N; i++) {
        cout << "? 1 " << i << '\n' << flush;
        cin >> prod[i];
        if (-1 == prod[i]) return 0;
        m = min(m, prod[i]);
        if (prod[i] == 3) t = 1;
    }
    if (m == 2 && t) {
        cout << "! 1";
        for (int i = 2; i <= N; i++)
            cout << ' ' << prod[i];
    }
    else {
        cout << "! " << m;
        for (int i = 2; i <= N; i++)
            cout << ' ' << prod[i]/m;
    }
    cout << '\n' << flush;
    return 0;
}
