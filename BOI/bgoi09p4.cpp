/*
Bulgarian OI '09 P4 - Frogs
Key Concepts: Data Structures (monotonic stack)
https://dmoj.ca/problem/bgoi09p4
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+5; 

int heights[MAXN];  // also stores the answer
int jumps[MAXN];
int mono_stack[MAXN], idx;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> heights[i];
    for (int i = 0; i < N; i++) cin >> jumps[i];

    idx = -1;
    for (int cur = N-1; cur >= 0; cur--) {
        while (idx >= 0 && mono_stack[idx] <= heights[cur]) idx--;
        mono_stack[++idx] = heights[cur];

        if (jumps[cur] > idx) heights[cur] = -1;
        else heights[cur] = mono_stack[idx-jumps[cur]];        
    }

    for (int i = 0; i < N; i++) cout << heights[i] << ' ';
    cout << '\n';

    return 0;
}