/*
Another Sorting
Key Concepts: Implementation
https://dmoj.ca/problem/anothersorting
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    if (a % 10 == b % 10) return a > b;
    return a % 10 < b % 10;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << "\n";

    return 0;
}