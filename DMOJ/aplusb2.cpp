/*
My initial attempt of this problem was written 3 years ago, and it was very VERY messy. 
Here is a complete rewrite. (it's still quite messy though)
https://dmoj.ca/problem/aplusb2
Solution by Kevin Guo
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100002;

short da[MAXN];
short db[MAXN];

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;

        bool pa = a[0] != '-';
        bool pb = b[0] != '-';
        int as = a.size();
        int bs = b.size();
        if (!pa) as--;
        if (!pb) bs--;
        int ms = max(as, bs);

        bool neg = 0;

        // store reversed strings
        memset(da, 0, sizeof(da));
        memset(db, 0, sizeof(db));
        for (int i = 1; i <= as; i++) da[i] = a[a.size()-i] - '0';
        for (int i = 1; i <= bs; i++) db[i] = b[b.size()-i] - '0';

        // add them
        if ((pa ^ pb) == 0) {
            for (int i = 1; i <= ms; i++) {
                da[i] += db[i];
                if (da[i] >= 10) {
                    da[i+1]++;
                    da[i] -= 10;
                }
            }
            if (!pa) neg = 1;
        }
        // subtract them
        else {
            for (int i = 1; i <= ms; i++) {
                da[i] -= db[i];
                if (da[i] < 0) {
                    da[i+1]--;
                    da[i] += 10;
                }
            }
            if (da[ms+1] == -1) {   // invert (inefficient)
                da[ms+1] = 0;
                for (int i = 1; i <= ms; i++) {
                    da[i] = 9 - da[i];
                }
                // ten's complement???
                for (int i = 1; i <= ms; i++) {
                    da[i]++;
                    if (da[i] >= 10) {
                        da[i] -= 10;
                    }
                    else break;
                }

                if (pa) neg = 1;
            }
            else if (pb) neg = 1;
        }

        int start = -1;
        for (int i = ms+1; i >= 1; i--) {
            if (da[i] != 0) {
                start = i;
                break;
            }
        }
        if (start == -1) cout << 0 << "\n";
        else {
            if (neg) cout << "-";
            for (int i = start; i >= 1; i--) {
                cout << da[i];
            }
            cout << "\n";
        }
    }

    return 0;
}