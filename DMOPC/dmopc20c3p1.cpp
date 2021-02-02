/*
DMOPC '20 Contest 3 P1 - Present Checking
Key Concepts: Implementation
https://dmoj.ca/problem/dmopc20c3p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

bool arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, x; cin >> n;
    while (n--) {
        cin >> x;
        if (arr[x]) {
            cout << "NO\n";
            return 0;
        }
        arr[x] = 1;
    }
    cout << "YES\n";
    return 0;
}