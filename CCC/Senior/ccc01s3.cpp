// https://dmoj.ca/problem/ccc01s3
#include <bits/stdc++.h>
using namespace std;

vector<int> points[26];
bool visited[26];

bool dfs(int n) {   // Can you reach point 1 from this point?
    if (visited[n])
        return false;
    if (n == 1) {
        return true;
    }
    visited[n] = 1;
    bool reachable = false;
    for (int i:points[n]) {
        if (i == -1) continue;
        reachable = reachable || dfs(i);
    }
    return reachable;
}


int main() {
    string s; cin >> s;
    while (s != "**") {
        int x = s[0] - 'A';
        int y = s[1] - 'A';
        points[x].push_back(y);
        points[y].push_back(x);
        cin >> s;
    }

    int score = 0;
    for (int i = 0; i < 26; i++) {
        for (int j:points[i]) {
            memset(visited, 0, sizeof(visited));
            int tmp1 = j; // disconnect opp direct
            vector<int>::iterator it = find(points[j].begin(), points[j].end(), i);
            int tmp2 = *it;
            *it = 0;
            j = -1;
            
            if (!dfs(0)) {
                score++;
                s[1] = i + 'A';
                s[0] = tmp1 + 'A';
                cout << s << endl;
            }
            j = tmp1;
            *it = tmp2;
        }
    }
    cout << "There are " << score << " disconnecting roads." << endl;
    return 0;
}