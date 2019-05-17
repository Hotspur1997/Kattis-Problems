#include <bits/stdc++.h>
#define SRC 0
using namespace std;
typedef vector<vector<long>> vv;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n,e; cin >> n >> e;
    vv c(n);
    while (e--) {
        long s,d; cin >> s >> d;
        s--; d--;
        c[s].push_back(d);
        c[d].push_back(s);
    }
    vector<bool> visited(n , false);
    queue<long> q;
    bool com = true;
    visited[SRC] = true;
    q.push(SRC);
    while (!q.empty()) {
        long u = q.front();
        q.pop();
        for (auto i = c[u].begin(); i != c[u].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                q.push(*i);
            }
        }
    }
    for (long i = 0; i < n; i++) {
        if (!visited[i]) {
            com = false;
            cout << i + 1 << '\n';
        }
    }
    if (com) cout << "Connected" << '\n';
}