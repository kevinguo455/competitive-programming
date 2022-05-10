/*
Code Jam 2021 Qualification Round Problem 3 - Median Sort
Key Concepts: Information Theory
https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int query(int a, int b, int c) {
    cout << a << ' ' << b << ' ' << c << '\n' << flush;
    int x; cin >> x;
    return x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T, N, Q, x; cin >> T >> N >> Q;
    for (int t = 1; t <= T; t++) {
        
        vector<int> ans(3, 0);
        cout << "1 2 3\n" << flush;
        cin >> ans[1];
        if (ans[1] == -1) return 0;

        for (int i = 1; i <= 3; i++) {
            if (i != ans[1]) {
                if (ans[0] == 0) ans[0] = i;
                else ans[2] = i;
            } 
        }

        for (int i = 4; i <= N; i++) {
            int l = -1, r = i-1, m1, m2; 

            while (r-l >= 3) {
                m1 = l+(r-l)/3;
                m2 = r-(r-l)/3;
                x = query(ans[m1], i, ans[m2]);
                
                if (x == -1) {
                    return 0;
                }
                else if (x == i) {
                    l = m1;
                    r = m2;
                }
                else if (x == ans[m1]) {
                    r = m1;
                }
                else if (x == ans[m2]) {
                    l = m2;
                }
            }

            if (r-l == 2) {
                if (l == -1) {
                    x = query(ans[l+1], i, ans[l+2]);
                    if (x == -1) return 0;
                    else if (x == i) l++;
                }
                else {
                    x = query(ans[l], i, ans[l+1]);
                    if (x == -1) return 0;
                    else if (x == ans[l+1]) l++;
                }
            }

            ans.insert(ans.begin()+l+1, i);
        }

        cout << ans[0];
        for (int i = 1; i < N; i++) cout << ' ' << ans[i];
        cout << '\n' << flush;
        cin >> x;
        if (x == -1) return 0;
    }

    return 0;
}