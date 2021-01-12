/*
AtCoder Beginner Contest 188 Problem C - ABC Tournament 
Key Concepts: Implementation
https://atcoder.jp/contests/abc188/tasks/abc188_c
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = (1<<16)+5; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin >> n;
    queue<int> q;
    for (int i = 0; i < (1<<n); i++) {
        cin >> arr[i];
        q.push(i);
    }
    while (q.size() > 2) {
        int s = q.size();
        for (int i = 0; i < s; i+=2) {
            int x = q.front(); q.pop();
            int y = q.front(); q.pop();
            if (arr[x] > arr[y]) q.push(x);
            else q.push(y);
        }
    }

    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    if (arr[x] < arr[y]) cout << x+1 << "\n";
    else cout << y+1 << "\n";

    return 0;
}