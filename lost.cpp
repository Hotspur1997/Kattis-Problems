#include <bits/stdc++.h>
#define SRC 0
using namespace std;
typedef pair<long,long> iPair;
typedef vector<vector<iPair>> vv;

void bfs(vv &c, vector<long> &d, long n) {
    queue<long> q;
    vector<long> dist(n + 1, LONG_MAX);
    d[SRC] = 0;
    dist[SRC] = 0;
    q.push(SRC);
    while (!q.empty()) {
        long u = q.front();
        q.pop();
        for (auto i = c[u].begin(); i != c[u].end(); i++) {
            long v = i -> first;
            long w = i -> second;
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                d[v] = w;
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                if (d[v] > w) d[v] = w;
            }
        }
    }
}
int main() {
    long n,e, res = 0, size = 0; cin >> n >> e;
    vector<long> d(n + 1, LONG_MAX);
    unordered_map<string, long> m;
    vv c(n + 1);
    bool ac = true;
    m["English"] = size;
    size++;
    for (long i = 0; i < n; i++) {
        string s; cin >> s;
        m[s] = size;
        size++;
    }
    while (e--) {
        string s1, s2;
        long w; cin >> s1 >> s2 >> w;
        c[m[s1]].push_back(make_pair(m[s2], w));
        c[m[s2]].push_back(make_pair(m[s1], w));
    }
    bfs(c, d, n);
    for (long i = 1; i < n + 1; i++) {
        if (d[i] != LONG_MAX) {
            res += d[i];
        } else {
            ac = false;
            break;
        }
    }
    if (ac) {
        cout << res;
    } else cout << "Impossible";
}