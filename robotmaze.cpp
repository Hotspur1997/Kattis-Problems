#include <bits/stdc++.h>
#define U 0
#define D 1
#define L 2
#define R 3
#define CONST 4
#define INF 10000000
using namespace std;
typedef pair<long,long> iPair;
typedef pair<pair<long,long>, pair<long,long>> Pair;
typedef vector<vector<char>> vv;
typedef vector<vector<vector<vector<long>>>> vvvv;

bool inbound(long i, long j, long r, long c) {
    return i >= 0 && j >= 0 && i < r && j < c;
}

bool hardCheck(long dir, long i) {
    return ((dir == U && i != D) || (dir == D && i != U) || (dir == L && i != R) || (dir == R && i != L));
}

long bfs(vv &a, vvvv &d, long rmax, long cmax, long rsrc, long csrc, long rdst, long cdst) {
    queue<Pair> q;
    long res = LONG_MAX;
    for (long i = 0; i < CONST; i++) {
        d[rsrc][csrc][i][0] = 0;
        q.push(make_pair(make_pair(rsrc,csrc),make_pair(i,0)));
    }
    vector<iPair> move = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    while (!q.empty()) {
        long r = q.front().first.first;
        long c = q.front().first.second;
        long dir = q.front().second.first;
        long s = q.front().second.second;
        if (r == rdst && c == cdst) {
            if (d[r][c][dir][s] < res) res = d[r][c][dir][s];
        } 
        q.pop();
        for (long i = 0; i < move.size(); i++) {
            long newr = r + move[i].first;
            long newc = c + move[i].second;
            if (inbound(newr,newc,rmax,cmax) && a[newr][newc] != 'B') {
               if (s == 2) {
                   if (i != dir && hardCheck(dir,i)) {
                       if (d[newr][newc][i][1] > d[r][c][dir][s] + 1) {
                           d[newr][newc][i][1] = d[r][c][dir][s] + 1;
                           q.push(make_pair(make_pair(newr,newc), make_pair(i,1)));
                       }
                   }
               } else {
                   if (hardCheck(dir,i)) {
                       if (i == dir) {
                           if (d[newr][newc][dir][s + 1] > d[r][c][dir][s] + 1) {
                               d[newr][newc][dir][s + 1] = d[r][c][dir][s] + 1;
                               q.push(make_pair(make_pair(newr,newc), make_pair(dir,s + 1)));
                           }
                       } else {
                           if (d[newr][newc][i][1] > d[r][c][dir][s] + 1) {
                               d[newr][newc][i][1] = d[r][c][dir][s] + 1;
                               q.push(make_pair(make_pair(newr,newc), make_pair(i, 1)));
                           }
                       }
                   }
               }
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long num; cin >> num;
    while (num--) {
        long r,c, rsrc, csrc, rdst, cdst; cin >> r >> c;
        vv a(r, vector<char>(c));
        for (long i = 0; i < r; i++) {
            for (long j = 0; j < c; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'R') {
                    rsrc = i;
                    csrc = j;
                }
                if (a[i][j] == 'D') {
                    rdst = i;
                    cdst = j;
                }
            }
        }
        vector<vector<vector<vector<long>>>> d (r, vector<vector<vector<long>>>(c, vector<vector<long>>(CONST, vector<long>(3, LONG_MAX))));
        long res = bfs(a,d,r,c,rsrc,csrc,rdst,cdst);
        if (res != LONG_MAX) {
            cout << res << '\n';
        } else cout << -1 << '\n';
    }
}