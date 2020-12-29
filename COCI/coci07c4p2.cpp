/*
COCI '07 Contest 4 #2 Veci
Key Concepts: Brute Force
https://dmoj.ca/problem/coci07c4p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 6, INF = 0x3f3f3f3f;
int arr[MAXN];
int p[MAXN];
int o[MAXN];

int n, l, ans = INF;

void eval() {
    int cn = 0;
    for (int i = 0; i < l; i++) {
        if (arr[p[i]] == 11) return;
        cn += arr[p[i]] * pow(10, i);
    }
    if (cn <= n) return;
    ans = min(ans, cn);
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    string s; cin >> s;
    n = stoi(s);
    l = s.length();
    for (int i = 0; i < l; i++) {
        arr[i] = s[i] - '0';
    }
    for (int i = l; i < MAXN; i++) {
        arr[i] = 11;
    }

    // woohooooo ugly brute force :)
    for (p[0] = 0; p[0] < MAXN; p[0]++) {
        for (p[1] = 0; p[1] < MAXN; p[1]++) {
            for (p[2] = 0; p[2] < MAXN; p[2]++) {
                for (p[3] = 0; p[3] < MAXN; p[3]++) {
                    for (p[4] = 0; p[4] < MAXN; p[4]++) {
                        for (p[5] = 0; p[5] < MAXN; p[5]++) {
                            bool skip = 0;
                            memset(o, 0, sizeof(o));
                            for (int i = 0; i < MAXN; i++) {
                                o[p[i]]++;
                                if (o[p[i]] > 1) {
                                    skip = 1;
                                    break;
                                }
                            }
                            if (skip) continue;
                            eval();
                        }
                    }
                } 
            }
        }
    }

    if (ans == INF) ans = 0;
    cout << ans << "\n";

    return 0;
}
