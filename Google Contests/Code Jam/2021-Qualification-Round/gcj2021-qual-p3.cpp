/*
Code Jam 2021 Qualification Round Problem 3 - Reversort Engineering
Key Concepts: Greedy Algorithms
https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, C; cin >> N >> C;

        if (C < N-1 || C > N*(N+1)/2-1) {
            cout << "Case #" << t << ": IMPOSSIBLE\n";
            continue;
        }

        C -= N-1;

        vector<int> ans(N);
        iota(ans.begin(), ans.end(), 1);
        int l = 0, r = N;

        for (int i = N-1; i > 0; i--) {
            if (C > i) {
                reverse(ans.begin()+l, ans.begin()+r);
                if (ans[l] < ans[r-1]) l++;
                else r--;
                C -= i;
            }
            else {
                if (ans[l] < ans[r-1]) reverse(ans.begin()+l, ans.begin()+l+C+1);
                else reverse(ans.begin()+r-C-1, ans.begin()+r);
                break;
            }
        }

        cout << "Case #" << t << ": " << ans[0];
        for (int i = 1; i < N; i++) cout << ' ' << ans[i]; 
        cout << '\n';
    }

    return 0;
}