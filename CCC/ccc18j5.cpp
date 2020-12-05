// https://dmoj.ca/problem/ccc18j5
#include <bits/stdc++.h>
using namespace std;

vector<int> book[10001];
queue<pair<int, int> > toVisit;
bool visited[10001];

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    int pages; cin >> pages;

    for (int i = 1; i <= pages; i++) {
        int n, m;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> m;
            book[i].push_back(m);
        }
    }
    int shortestPath = -1;
    toVisit.push(make_pair(1,1));
    while (!toVisit.empty()) {
        int x = toVisit.front().first;
        int y = toVisit.front().second;
        visited[x] = 1;
        if (book[x].size() == 0) {
            if (shortestPath == -1) {
                shortestPath = y;
            }
        }
        else {
            for (int i:book[x]) {
                if (!visited[i]) {
                    toVisit.push(make_pair(i,y+1));
                }
            }
        }
        toVisit.pop();
    }
    for (int i = 1; i <= pages; i++) {
        if (!visited[i]) {
            cout << "N" << endl;
            break;
        }
        if (i == pages)
            cout << "Y" << endl;
    }
    cout << shortestPath << endl;
    return 0;
}