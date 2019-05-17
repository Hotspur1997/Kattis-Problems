#include <bits/stdc++.h>
#define SRC 0
using namespace std;
typedef vector<vector<char>> vv;
typedef pair<long,long> iPair;

long relabel(long i, long j, long c) {
    return c * i + j;
}

bool inbound(long i, long j, long r) {
    return i >= 0 && j >= 0 && i < r && j < r;
}

int main() {
    long r, rsrc, csrc; cin >> r;
    vv a(r, vector<char> (r));
    for (long i = 0; i < r; i++) {
        for (long j = 0; j < r; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'K') {
                rsrc = i;
                csrc = j; 
            }
        }
    }
    if (rsrc == SRC && csrc == SRC) {
        cout << 0;
        return 0;
    }
    queue<iPair> q;
    q.push(make_pair(rsrc, csrc));
    vector<long> d(r * r, LONG_MAX);
    d[relabel(rsrc,csrc, r)] = 0;
    vector<iPair> move = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
    while (!q.empty()) {
        long currR = q.front().first;
        long currC = q.front().second;
        q.pop();
        long src = relabel(currR, currC, r);
        for (iPair i : move) {
            long newr = currR + i.first;
            long newc = currC + i.second;
            if (inbound(newr,newc,r) && a[newr][newc] != '#') {
                long dst = relabel(newr,newc,r);
                if (d[dst] > d[src] + 1) {
                    d[dst] = d[src] + 1;
                    q.push(make_pair(newr,newc));
                }
            }
        }
    }
    if (d[SRC] != LONG_MAX) {
        cout << d[SRC];
    } else cout << -1;
}