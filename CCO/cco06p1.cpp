/*
CCO '06 P1 - CN Tower
Key Concepts: Implementation
https://dmoj.ca/problem/cco06p1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string s;
    int n; cin >> n;
    vector<float> v(n);
    for (int i = 0; i < n; i++) {
        cin >> s >> v[i];
    }
    
    sort(v.begin(), v.end());
    float maxdist = 360 - v[n-1] + v[0];
    for (int i = 0; i < n-1; i++) {
        maxdist = max(maxdist, v[i+1] - v[i]);
    }

    cout << ceil((360-maxdist) * 12) << endl;

    return 0;
}