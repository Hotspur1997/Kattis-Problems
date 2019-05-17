#include <bits/stdc++.h>
#define SRC 0
using namespace std;
typedef pair<long, long> iPair;
typedef vector<vector<iPair>> vv;

void modified_dijkstra (vv c, long* dist, long* o, long* p, long d) {
    
    p[SRC] = o[SRC];
    dist[SRC] = 0;
    set<iPair> s;
    s.insert(make_pair(dist[SRC], SRC));
    while(!s.empty()) {
        iPair t = *(s.begin());
        s.erase(*s.begin());
        long u = t.second;
        for (auto i = c[u].begin(); i != c[u].end(); i++) {
            long v = i -> first;
            long w = i -> second;
            if (dist[u] + w < dist[v]) {
                if (dist[v] != LONG_MAX) s.erase(s.find(make_pair(dist[v],v)));
                dist[v] = dist[u] + w;
                p[v] = p[u] + o[v];
                s.insert(make_pair(dist[v],v));
            } else if (dist[u] + w == dist[v]) {
                if (p[u] + o[v] > p[v]) {
                    if (dist[v] != LONG_MAX) s.erase(s.find(make_pair(dist[v],v)));
                    p[v] = p[u] + o[v];
                    s.insert(make_pair(dist[v],v));
                }    
            }
        }
    }
}
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    long n,e,d; cin >> n;
    d = n - 1;
    long* o = new long[n];
    long* p = new long[n];
    long* dist = new long[n];
    for (long i = 0; i < n; i++) {
        cin >> o[i];
        p[i] = 0;
        dist[i] = LONG_MAX;
    }
    vv c(n); cin >> e;
    for (long i = 0; i < e; i++) {
        long src,dst,w; cin >> src >> dst >> w;
        src--; dst--;
        c[src].push_back(make_pair(dst,w));
        c[dst].push_back(make_pair(src,w));
    }
    modified_dijkstra(c, dist, o, p, d);
    if (dist[d] == LONG_MAX) { 
        cout << "impossible" << '\n';
    } else {
        cout << dist[d] << " " << p[d] << '\n';
    }
    delete[] o; o = 0;
    delete[] p; p = 0;
    delete[] dist; dist = 0;
}