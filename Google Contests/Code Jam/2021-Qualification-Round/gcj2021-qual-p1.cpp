/*
Code Jam 2021 Qualification Round Problem 1 - Reversort
Key Concepts: Implementation
https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; 

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {

        // Follow instructions outlined in problem statement
        int N; cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; i++) cin >> v[i];
        int ans = 0;

        for (int i = 0; i < N-1; i++) {
            int mn = INF, mp;
            for (int j = i; j < N; j++) {
                if (v[j] < mn) {
                    mn = v[j];
                    mp = j;
                }
            }
            reverse(v.begin()+i, v.begin()+mp+1);
            ans += mp-i+1;
        }

        cout << "Case #" << t << ": " << ans << '\n';
    }

    return 0;
}