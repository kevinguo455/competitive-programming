/*
Mock CCC '18 Contest 5 J3/S1 - Median Triples
Key Concepts: Brute Force
https://dmoj.ca/problem/nccc5j3s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101; 

int arr[MAXN];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, X; cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                vector<int> v(3);
                v[0] = arr[i];
                v[1] = arr[j];
                v[2] = arr[k];
                sort(v.begin(), v.end());
                if (v[1] == X) ans++;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}