#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<long>> vv;
typedef pair<long, long> iPair;

void khan(vv &c,  vector<long> &d, vector<long> &indegree, long n, long &max) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    long inc = n - 1;
    for (long i = 0; i < n; i++) {
        if (!indegree[i]) pq.push(make_pair(d[i], i));
    }
    while (!pq.empty()) {
        long u = pq.top().second;
        d[u] += inc;
        if (d[u] > max) max = d[u];
        pq.pop();
        inc--;
        for (auto i = c[u].begin(); i != c[u].end(); i++) {
            if (--indegree[*i] == 0) pq.push(make_pair(d[*i], *i));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n, max = -LONG_MAX; cin >> n;
    vv c(n);
    vector<long> d(n, 0), indegree(n, 0);
    for (long i = 0; i < n; i++) {
        cin >> d[i];
        long m; cin >> m;
        for (long j = 0; j < m; j++) {
            long o; cin >> o;
            o--;
            c[i].push_back(o);
            indegree[o]++;
        }
    }
    khan(c, d, indegree, n, max);
    cout << max;
}