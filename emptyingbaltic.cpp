#include <bits/stdc++.h>
using namespace std;
typedef tuple<long,long,long> iTuple;
typedef pair<long,long> iPair;

long relabel(long i, long j, long c) {
    return c * i + j;
}

bool inbound(long i, long j, long r, long c) {
    return i >= 0 && j >= 0 && i < r && j < c;
}

long dijkstra(vector<vector<long>> &a, long sr, long sc, long rmax, long cmax) {
    priority_queue<iTuple, vector<iTuple>> pq;
    vector<long> d(rmax * cmax, -LONG_MAX);
    long res = 0;
    vector<iPair> move = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    d[relabel(sr,sc,cmax)] = abs(a[sr][sc]);
    pq.push(make_tuple(d[relabel(sr,sc,cmax)], sr, sc));
    while (!pq.empty()) {
        long r = get<1>(pq.top());
        long c = get<2>(pq.top());
        pq.pop();
        long src = relabel(r,c,cmax);
        for (iPair i : move) {
            long newr = r + i.first;
            long newc = c + i.second;
            if (inbound(newr,newc,rmax,cmax)) {
                long dst = relabel(newr, newc, cmax);
                if (a[newr][newc] < 0) {
                    if (abs(a[newr][newc]) < d[src]) {
                        if (abs(a[newr][newc]) > d[dst]) {
                            d[dst] = abs(a[newr][newc]);
                            pq.push(make_tuple(d[dst], newr, newc));
                        }
                    } else if (d[src] > d[dst]) {
                        d[dst] = d[src];
                        pq.push(make_tuple(d[dst], newr, newc));
                    }
                }
            }
        }
    }
    for (long i = 0; i < rmax * cmax; i++) {
        if (d[i] != -LONG_MAX) res += d[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long r,c, sr, sc; cin >> r >> c;
    vector<vector<long>> a(r);
    for (long i = 0; i < r; i++) {
        a[i].resize(c);
        for (long j = 0; j < c; j++) cin >> a[i][j];
    }
    cin >> sr >> sc;
    sr--; sc--;
    cout << dijkstra(a, sr, sc, r, c);
}