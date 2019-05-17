#include <bits/stdc++.h>
using namespace std;

void bfs (unordered_map<string, vector<string>> &m, unordered_map<string, bool> &visited, unordered_map<string, bool> &colour, string src) {
    queue<string> q;
    q.push(src);
    visited[src] = true;
    colour[src] = true;
    while (!q.empty()) {
        src = q.front();
        q.pop();
        for (auto i = m[src].begin(); i != m[src].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                colour[*i] = !colour[src];
                q.push(*i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n,e; cin >> n;
    bool ac = true;
    unordered_map<string, vector<string>> m;
    unordered_map<string, bool> visited, colour;
    vector<string> items(n), walter, jesse, queries;
    for (long i = 0; i < n; i++) cin >> items[i];
    cin >> e;
    for (long i = 0; i < e; i++) {
        string s,d; cin >> s >> d;
        queries.push_back(s);
        visited[s] = false;
        visited[d] = false;
        m[s].push_back(d);
        m[d].push_back(s);
    }
    for (long i = 0; i < queries.size(); i++) {
        if (!visited[queries[i]]) bfs(m, visited, colour, queries[i]);
    }
    
    for (auto i = m.begin(); i != m.end(); i++) {
        for (auto j = (i -> second).begin(); j != (i -> second).end(); j++) {
            if (colour[i -> first] == colour[*j]) {
                ac = false;
                break;
            }
        }
        if (!ac) break;
    }
    if (!ac) {
        cout << "impossible";
        return 0;
    }
    for (long i = 0; i < n; i++) {
        if (!m.count(items[i])) {
            walter.push_back(items[i]);
        } else {
            if (colour[items[i]]) {
                walter.push_back(items[i]);
            } else jesse.push_back(items[i]);
        }
    }
    for (long i = 0; i < walter.size(); i++) cout << walter[i] << " ";
    cout << '\n';
    for (long i = 0; i < jesse.size(); i++) cout << jesse[i] << " ";
}