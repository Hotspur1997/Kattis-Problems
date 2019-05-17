#include <bits/stdc++.h>
using namespace std;
typedef pair<long, long> iPair;
typedef tuple<long, long, bool> iTuple;
typedef vector<vector<iPair>> vv;

void modified_dijkstra(vv &c, vector<iPair> &d, long src, long e1, long e2) {
    priority_queue<iTuple, vector<iTuple>, greater<iTuple>> pq;
    d[src].first = 0;
    pq.push(make_tuple(d[src].first, src, false));
    while (!pq.empty()) {
        src = get<1>(pq.top());
        bool used = get<2>(pq.top());
        long weight = get<0>(pq.top());
        pq.pop();
        for (auto i = c[src].begin(); d[src].first >= weight && i != c[src].end(); i++) {
            long v = i -> first;
            long w = i -> second;
            if (d[v].first > d[src].first + w) {
                d[v].first = d[src].first + w;
                if ((e1 == src && e2 == v) || (e1 == v && e2 == src)) {
                    d[v].second = true;
                    pq.push(make_tuple(d[v].first, v, true));
                } else {
                    d[v].second = used;
                    pq.push(make_tuple(d[v].first, v, used));
                }
            } else if (d[v].first == d[src].first + w) {
                if (((e1 == src && e2 == v) || (e1 == v && e2 == src))) {
                    d[v].second = true;
                    pq.push(make_tuple(d[v].first, v, true));
                } else if (used) {
                    d[v].second = used;
                    pq.push(make_tuple(d[v].first, v, used));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long num; cin >> num;
    while (num--) {
        long n,m,q; cin >> n >> m >> q;
        vector<iPair> d(n, make_pair(LONG_MAX, false));
        vector<long> res;
        vv c(n);
        long src, e1, e2; cin >> src >> e1 >> e2;
        src--; e1--; e2--;
        while (m--) {
            long s,d,w; cin >> s >> d >> w;
            s--; d--;
            c[s].push_back(make_pair(d,w));
            c[d].push_back(make_pair(s,w));
        }
        modified_dijkstra(c, d, src, e1, e2);
        while (q--) {
            long query; cin >> query;
            query--;
            if (d[query].second && d[query].first != LONG_MAX) res.push_back(query);
        }
        sort(res.begin(), res.end());
        for (long i = 0; i < res.size(); i++) cout << res[i] + 1 << " ";
        cout << '\n';
    }
}