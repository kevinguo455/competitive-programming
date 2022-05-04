/*
PEG Test '14 - Fire
Key Concepts: Simple Math
https://dmoj.ca/problem/avatarfire
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    unsigned int n, k; cin>>n>>k;
    priority_queue<unsigned int> leaves;
    unsigned int x;
    for (unsigned int i = 0; i < n; i++) {
        cin >> x;
        if (leaves.size() <= k) {
            leaves.push(x);
        }
        else {
            if (leaves.top() > x) {
                leaves.pop();
                leaves.push(x);
            }
        }
    }
    x = leaves.top();
    while (leaves.size() != 1) {
        leaves.pop();
    }
    unsigned int y = leaves.top();
    if (n == k) {
        cout << 2*y << endl;
        return 0;
    }
    leaves.pop();
    cout << min(x,y*2) << endl;

    return 0; 
}