/*
Multiplication Improvement
Key Concepts: Implementation
https://dmoj.ca/problem/mizxyl
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    vector<int> v;
    string s, t; cin >> s;
    stringstream ss(s);
    ll ans = 1;
    
    while (getline(ss, t, 'x')) {
        v.push_back(stoi(t));
        ans *= stoi(t);
    }
    sort(v.begin(), v.end());

    cout << v[0];
    for (int i = 1; i < v.size(); i++) cout << 'x' << v[i];
    cout << '\n' << ans;

    return 0;
}