#include <bits/stdc++.h>
using namespace std;
typedef pair<long,long> iPair;

long relabel(long i , long j, long c) {
    return c * i + j;
}

bool inbound(long i, long j, long rmax, long cmax) {
    return i >= 0 && j >= 0 && i < rmax && j < cmax;
}

void bfs(vector<vector<char>> &a, vector<bool> &visited, long rsrc, long csrc, long rmax, long cmax) {
    queue<iPair> q;
    visited[relabel(rsrc,csrc,cmax)] = true;
    q.push(make_pair(rsrc, csrc));
    vector<iPair> move = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    while (!q.empty()) {
        long r = q.front().first;
        long c = q.front().second;
        long src = relabel(r,c,cmax);
        q.pop();
        for (iPair i : move) {
            long newr = r + i.first;
            long newc = c + i.second;
            if (inbound(newr,newc,rmax,cmax)) {
                long dst = relabel(newr,newc, cmax);
                if (!visited[dst] && a[newr][newc] == '#') {
                    visited[dst] = true;
                    q.push(make_pair(newr,newc));
                }
            }
        }
    }
    
}

int main() {
    long r,c, res = 0; cin >> r >> c;
    vector<bool> visited(r * c, false);
    vector<vector<char>> a(r);
    for (long i = 0; i < r; i++) {
        a[i].resize(c);
        for (long j = 0; j < c; j++) cin >> a[i][j];
    }
    for (long i = 0; i < r; i++) {
        for (long j = 0; j < c; j++) {
            if (!visited[relabel(i,j,c)] && a[i][j] == '#') {
                bfs(a, visited, i, j, r, c);
                res++;
            }
        }
    }
    cout << res;
}