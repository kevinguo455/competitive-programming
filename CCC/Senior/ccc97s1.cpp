/*
CCC '97 S1 - Sentences
Key Concepts: Implementation
https://dmoj.ca/problem/ccc97s1
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin >> T;
    while (T--) {

        int A, B, C; cin >> A >> B >> C;
        vector<string> a(A), b(B), c(C);
        
        cin.ignore();
        for (int i = 0; i < A; i++) getline(cin, a[i]);
        for (int i = 0; i < B; i++) getline(cin, b[i]);
        for (int i = 0; i < C; i++) getline(cin, c[i]);
        
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < C; k++) {
                    cout << a[i] << ' ' << b[j] << ' ' << c[k] << ".\n";
                }
            }
        }
        
    }

    return 0;
}