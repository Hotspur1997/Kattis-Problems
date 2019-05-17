#include <bits/stdc++.h>
#define SRC 0
using namespace std;
typedef pair<long, long> iPair;
typedef tuple<long, long, long> iTuple;

int relabel(long i, long j, long c) {
    return c * i + j;
}

bool inbound(long i, long j, long r, long c) {
    return i < r && i >= 0 && j < c && j >= 0;
}

void modified_dijkstra(vector<vector<long>> &a, vector<long> &d, long rmax, long cmax) {
    d[relabel(SRC, SRC, cmax)] = 0;
    priority_queue<iTuple, vector<iTuple>, greater<iTuple>> pq;
    pq.push(make_tuple(d[relabel(SRC, SRC, cmax)], SRC, SRC));
    vector<iPair> move = {{1,0}, {0,1}, {0,-1}, {-1,0}};
    while (!pq.empty()) {
        int r = get<1>(pq.top());
        int c = get<2>(pq.top());
        int src = relabel(r, c, cmax);
        pq.pop();
        for (iPair i : move) {
            int rnew = r + i.first;
            int cnew = c + i.second;
            if (inbound(rnew,cnew, rmax, cmax)) {
                int dst = relabel(rnew, cnew, cmax);
                int diff = a[rnew][cnew] - a[r][c];
                if (d[src] < diff) {
                    if (diff < d[dst]) {
                        d[dst] = diff; 
                        pq.push(make_tuple(d[dst], rnew, cnew));
                    }
                } else if (d[src] < d[dst]) {
                    d[dst] = d[src];
                    pq.push(make_tuple(d[dst], rnew, cnew));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long r,c; cin >> r >> c;
    vector<vector<long>> a(r);
    for (long i = 0; i < r; i++) a[i].resize(c);
    for (long i = 0; i < r; i++) {
        for (long j = 0; j < c; j++) cin >> a[i][j];
    }
    vector<long> d(r *c, LONG_MAX);
    modified_dijkstra(a, d, r, c);
    cout << d[relabel(r - 1, c - 1, c)];
}