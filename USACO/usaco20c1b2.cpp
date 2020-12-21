/*
USACO 2020 December Contest, Bronze - Problem 2. Daisy Chains
Key Concepts: Implementation, Prefix Sum Array
http://www.usaco.org/index.php?page=viewproblem&cpid=1048
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 102;

int arr[MAXN];
int psa[MAXN]; 

int s(int l, int r) {   // sum from left index to right index, inclusive
    return psa[r+1] - psa[l];
}

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) {       // init
        cin >> arr[i];
        psa[i+1] += arr[i];
        psa[i+1] += psa[i];
    }

    int c = 0;
    for (int l = 0; l < n; l++) {       // Two Pointers (inclusive)
        for (int r = l; r < n; r++) {
            int a = s(l,r);                  // calculate average of range
            if (a % (r-l+1) != 0) continue;
            a /= (r-l+1);

            for (int i = l; i <= r; i++) {   // find average flower
                if (arr[i] == a) {
                    c++;
                    break;
                }
            }
        }
    }

    cout << c << "\n";

    return 0;
}