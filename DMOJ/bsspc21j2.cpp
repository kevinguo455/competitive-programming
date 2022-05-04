/*
BSSPC '21 J2 - James and Youtube
Key Concepts: Implementation, Brute Force
https://dmoj.ca/problem/bsspc21j2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1450; 

bitset<MAXN> arr;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int M, a, b; cin >> M;
    while (M--) {
        cin >> a >> b;
        for (int i = a; i <= b; i++) arr[i] = 1;
    }
    int N; cin >> N;
    while (N--) {
        cin >> a >> b;
        for (int i = a; i <= b; i++) {
            if (arr[i]) {
                cout << "Break is Over! Stop playing games! Stop watching Youtube!\n";
                break;
            }
            if (i == b) cout << ":eyy:\n";
        }
    }

    return 0;
}