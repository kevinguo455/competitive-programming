/*
Ren Ashbell
Key Concepts: Implementation
https://dmoj.ca/problem/stnbd1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for (int i = a; i < b; i++)
#define fio cin.tie(0); cout.tie(0); ios::sync_with_stdio(0)

int main() {
    fio;

    int n, x, y; cin >> n >> x;
    f(i,1,n) {
        cin >> y;
        if (y >= x) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}