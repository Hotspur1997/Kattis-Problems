#include <bits/stdc++.h>
using namespace std;
typedef pair<long, long> iPair;
typedef vector<vector<iPair>> vv;

void modified_dijkstra(vv &c, vector<long> &d, map<iPair, iPair> &m, long src) {
    
    set<iPair> s;
    s.insert(make_pair(d[src], src));
    while (!s.empty()) {
        iPair temp = *(s.begin());
        int u = temp.second;
        int weight = temp.first;
        s.erase(s.begin());
        for (auto i = c[u].begin(); i != c[u].end(); i++) {
            int v = i -> first;
            int w = i -> second;
            auto it = m.find(make_pair(u,v));
            if (it != m.end() && (d[u] >= (it -> second).first && d[u] < (it -> second).second)) {
                if ((it -> second).second + w < d[v]) {
                    if (d[v] != LONG_MAX) s.erase(s.find(make_pair(d[v],v)));
                    d[v] = (it -> second).second + w;
                    s.insert(make_pair(d[v],v));
                }
            } else if (d[u] + w < d[v]) {
                if (d[v] != LONG_MAX) s.erase(s.find(make_pair(d[v],v)));
                d[v] = d[u] + w;
                s.insert(make_pair(d[v],v));
            }
        }
    }
}
int main() {
    
    long n,e, t = 0; cin >> n >> e;
    long s,dest,o, g_num; cin >> s >> dest >> o >> g_num;
    s--; dest--;
    vector<long> g_n(g_num);
    map<iPair, iPair> m;
    for (long i = 0; i < g_num; i++) {
        int dummy; cin >> dummy;
        dummy--;
        g_n[i] = dummy;
    }
    vector<vector<long>> a_m(n);
    vector<long> d(n, LONG_MAX);
    for (long i = 0; i < n; i++) {
        a_m[i].resize(n);
        for (long j = 0; j < n; j++) a_m[i][j] = 0;
    }
    vv c(n);
    for (long i = 0; i < e; i++) {
        int s,d,w; cin >> s >> d >> w;
        s--; d--;
        a_m[s][d] = w;
        a_m[d][s] = w;
        c[s].push_back(make_pair(d,w));
        c[d].push_back(make_pair(s,w));
    }
    for (long i = 0; i < g_num - 1; i++) {
        long prevT = t;
        t += a_m[g_n[i]][g_n[i + 1]];
        m[make_pair(g_n[i], g_n[i + 1])] = make_pair(prevT, t);
        m[make_pair(g_n[i + 1], g_n[i])] = make_pair(prevT, t);
    }
    d[s] = o;
    modified_dijkstra(c, d, m, s);
    cout << d[dest] - o;
}