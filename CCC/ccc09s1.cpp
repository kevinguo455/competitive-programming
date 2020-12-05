// https://dmoj.ca/problem/ccc09s1
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e8+1;
const int SIXTH = 21;

int main() {
    set<int> n;
    for (int i = 0; i <= SIXTH; i++) {
        n.insert(pow(i,6));
    }
    int l, u; cin >> l >> u;
    set<int>::iterator lower, upper;
    lower = n.lower_bound(l);
    upper = n.upper_bound(u);
    cout << distance(lower, upper) << endl;
    return 0;
}