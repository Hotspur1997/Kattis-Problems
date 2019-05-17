#include <bits/stdc++.h>
using namespace std;
typedef pair<long, long> iPair;
typedef tuple<long, long, long> iTuple;

long relabel(long i, long j, long c) {
    return c * i + j;
}

bool inbound(long i, long j, long r, long c) {
    return i >= 0 && j >= 0 && i < r && j < c;
}
void dijkstra(vector<vector<char>> &a, long rmax, long cmax) {
    priority_queue<iTuple, vector<iTuple>, greater<iTuple>> pq;
    long min = LONG_MAX;
    iPair key;
    map<iPair, iPair> pred;
    vector<long> d(rmax * cmax, LONG_MAX);
    vector<iPair> move = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    for (long i = 0; i < cmax; i++) {
        d[relabel(0,i, cmax)] = a[0][i] - '0';
        pq.push(make_tuple(d[relabel(0,i,cmax)], 0, i));
    }
    while (!pq.empty()) {
        long r = get<1>(pq.top());
        long c = get<2>(pq.top());
        long weight = get<0>(pq.top());
        pq.pop();
        long src = relabel(r,c,cmax);
        if (d[src] >= weight) {
            for (iPair i : move) {
                long newr = r + i.first;
                long newc = c + i.second;
                if (inbound(newr, newc, rmax, cmax)) {
                    long dst = relabel(newr, newc, cmax);
                    if (d[dst] > d[src] + (a[newr][newc] - '0')) {
                        d[dst] = d[src] + (a[newr][newc] - '0');
                        pred[make_pair(newr,newc)] = make_pair(r,c);
                        pq.push(make_tuple(d[dst], newr, newc));
                    }
                }
            }
        }
    }
    for (long i = 0; i < cmax; i++) {
        if (d[relabel(rmax - 1, i, cmax)] < min) {
            min = d[relabel(rmax - 1, i, cmax)];
            key = make_pair(rmax - 1, i);
        }
    }
    while (pred.count(key)) {
        a[key.first][key.second] = ' ';
        key = pred[key];
    }
    a[key.first][key.second] = ' ';
}

int main() {
    long r, c;
    while (1) {
      cin >> r >> c;
      if (!r && !c) break;
      vector<vector<char>> a(r);
      for (long i = 0; i < r; i++) {
          a[i].resize(c);
          for (long j = 0; j < c; j++) cin >> a[i][j];
      }
      dijkstra(a,r,c);
      for (long i = 0; i < r; i++) {
          for (long j = 0; j < c; j++) cout << a[i][j];
          cout << '\n';
      }
      cout << '\n';
    }
}