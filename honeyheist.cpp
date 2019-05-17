#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<long>> vv;
typedef pair<long,long> iPair;

long relabel(long i, long j, long r) {
    return i * (2 * r - 1) + j;
}
bool inbound(long i, long j, long r) {
    return i >= 0 && j >= 0 && i < 2 * r - 1 && j < 2 * r - 1;
}

void bfs(vv &a, unordered_set<long> &s, vector<long> &d, long R, long rsrc, long csrc) {
    vector<bool> v((2 * R - 1) * ( 2 * R - 1), false);
    queue<iPair> q;
    q.push(make_pair(rsrc,csrc));
    long start = relabel(rsrc,csrc, R);
    d[start] = 0;
    v[start] = true;
    vector<iPair> move = {{-1,0}, {1,0}, {0,1}, {0,-1}, {-1,-1}, {1,1}};
    while (!q.empty()) {
        long r = q.front().first;
        long c = q.front().second;
        long src = relabel(r,c,R);
        q.pop();
        for (iPair i : move) {
            long newr = r + i.first;
            long newc = c + i.second;
            long dst = relabel(newr,newc,R);
            if (inbound(newr,newc, R) && a[newr][newc] != -1 && !v[dst]) {
                if (!s.count(a[newr][newc])) {
                    d[dst] = d[src] + 1;
                    v[dst] = true;
                    q.push(make_pair(newr,newc));
                }
            }
        }
    }
}

int main() {
    long r,n,a,b,e; cin >> r >> n >> a >> b >> e;
    long row = 2 * r - 1;
    long rsrc, csrc, rdst, cdst;
    unordered_set<long> s;
    while (e--) {
        long d; cin >> d;
        s.insert(d);
    }
    vv c(row, vector<long> (row, -1));
    vector<long> d(row * row, LONG_MAX);
    long currVal = 1;
    long cCount = r;
    for (long i = 0; i < r; i++) {
        for (long j = 0; j < cCount; j++) {
            c[i][j] = currVal;
            currVal++;
        }
        cCount++;
    }
    cCount -= 2;
    for (long i = r; i < row; i++) {
        long start = 2 * r - 1 - cCount;
        for (long j = start; j < 2 * r - 1; j++) {
            c[i][j] = currVal;
            currVal++;
        }
        cCount--;
    }
    for (long i = 0; i < 2 * r - 1; i++) {
        for (long j = 0; j < 2 * r - 1; j++) {
            if (c[i][j] == a) {
                rsrc = i;
                csrc = j;
            }
            if (c[i][j] == b) {
                rdst = i;
                cdst = j;
            }
        }
    }
    bfs (c, s, d, r, rsrc, csrc);
    if (d[relabel(rdst,cdst,r)] <= n) {
        cout << d[relabel(rdst,cdst,r)];
    } else cout << "No";
}