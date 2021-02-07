/*
Given a sequence of integers, calculate its median in an online manner.
*/
#include <bits/stdc++.h>
using namespace std;

int N; 
priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;

int average(int a, int b) {
    return (a+b)/2;
}

void add_element(int n) {
    // Add the element
    if (l.empty() || n <= l.top()) l.push(n);
    else r.push(n);

    // Rebalance heaps
    if (l.size() > r.size() + 1) {
        r.push(l.top());
        l.pop();
    }
    else if (l.size() + 1 < r.size()) {
        l.push(r.top());
        r.pop();
    }
}

int get_median() {
    if (l.size() > r.size()) return l.top();
    if (l.size() < r.size()) return r.top();
    return average(l.top(), r.top());
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> N;

    for (int i = 0, x; i < N; i++) {
        cin >> x;
        add_element(x);
        cout << get_median() << '\n' << flush;
    }

    return 0;
}