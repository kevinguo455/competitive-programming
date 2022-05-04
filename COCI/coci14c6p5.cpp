/*
COCI '14 Contest 6 #5 Neo
Key Concepts: Monotonic Stack (maximal rectangle under histogram, maximal rectangle in 2D grid)
https://dmoj.ca/problem/coci14c6p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005; 

int R, C, ans;
int arr[MAXN][MAXN];
int h[MAXN];

// push the index onto monotonic increasing stack
void push(int idx, stack<int> &mono_stack) {
    while (h[mono_stack.top()] >= h[idx] && mono_stack.top()) {
        int x = h[mono_stack.top()]+1;
        mono_stack.pop();
        ans = max(ans, x * (idx-mono_stack.top()));
    }
    mono_stack.push(idx);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // read input
    cin >> R >> C;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            cin >> arr[r][c];
        }
    }

    // run maximal rectangle under histogram for each row
    for (int r = 1; r < R; r++) {
        stack<int> mono_stack;      // {height, index}
        mono_stack.push(0);

        for (int c = 1; c < C; c++) {
            // update the histogram
            if (arr[r][c] + arr[r+1][c+1] <= arr[r][c+1] + arr[r+1][c]) h[c]++;
            else h[c] = 0;
            push(c, mono_stack);
        }

        push(C, mono_stack);         // clear out all items still in stack
    }

    cout << ans << '\n';

    return 0;
}