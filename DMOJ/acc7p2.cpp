/*
Another Contest 7 Problem 2 - Code Review
Key Concepts: Implementation, Brute Force
https://dmoj.ca/problem/acc7p2
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e3+1; 

int arr[MAXN];
bitset<MAXN> sure;
int safe;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, S; cin >> N;
    iota(arr+1, arr+N+1, 1);
    random_shuffle(arr+1, arr+N+1);

    while (1) {
        for (int i = 1; i <= N; i++) cout << arr[i] << ' ';
        cout << '\n' << flush;
        cin >> S;
        if (S <= 0) break;

        int w = safe;
        for (int i = 1; i <= N; i++) {
            if (!sure[arr[i]] && i != S) {
                w = i;
                break;
            }
        }
        swap(arr[S], arr[w]);
        sure[S] = 1;
        sure[w] = 1;
        safe = S;
    }

    return 0;
}