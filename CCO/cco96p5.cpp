/*
CCO '96 P5 - All Roads Lead Where?
Key Concepts: Graph Theory (DFS), Implementation (Maps)
https://dmoj.ca/problem/cco96p5
Solution by Kevin Guo
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
map<string, vector<string> > cities;
queue<string> q;
vector<char> path;
bool vis[MAXN];
bool quit;
    
void dfs(string s1, string s2) {
    if (s1 == s2) {
        //good
        for (char c:path) {
            cout << c;
        }
        cout << s2[0] << endl;
        quit = 1;
        return;
    }
    map<string, vector<string> >::iterator it1 = cities.find(s1);
    int l1 = distance(cities.begin(), it1);
    vis[l1] = 1;
    path.push_back(s1[0]);
    for (string s:it1->second) {
        map<string, vector<string> >::iterator it2 = cities.find(s);
        int l2 = distance(cities.begin(), it2);
        if (!vis[l2]) {
            dfs(s, s2);
            if (quit) return;
        }
    }
    path.pop_back();
}

int main() {
    int n, queries; cin >> n >> queries;
    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        map<string, vector<string> >::iterator it1 = cities.find(s1), it2 = cities.find(s2);
        vector<string> v;
        if (it1 == cities.end() && it2 == cities.end()) {
            v.push_back(s2);
            cities.insert(make_pair(s1, v));
            v.clear();
            v.push_back(s1);
            cities.insert(make_pair(s2, v));
        }
        else if (it1 == cities.end()) {
            it2->second.push_back(s1);
            v.push_back(s2);
            cities.insert(make_pair(s1, v));
        }
        else if (it2 == cities.end()) {
            it1->second.push_back(s2);
            v.push_back(s1);
            cities.insert(make_pair(s2, v));
        }
        else {
            it1->second.push_back(s2);
            it2->second.push_back(s1);
        }
    }
    for (int i = 0; i < queries; i++) {
        cin >> s1 >> s2;
        path.clear();
        memset(vis, 0, sizeof(vis));
        quit = 0;
        dfs(s1, s2);
    }
    return 0;
}