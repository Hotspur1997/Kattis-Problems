#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vv;

long topological_sort(vector<int> indegree, vv &c, vector<int> &lab, int side, int n) {
    vector<queue<int>> q(2);
    long moves = 0;
    for (long i = 0; i < n; i++) {
        if (!indegree[i]) q[lab[i]].push(i);
    }
    while (!(q[0].empty() && q[1].empty())) {
        while (!q[side].empty()) {
            int u = q[side].front();
            q[side].pop();
            for (auto i = c[u].begin(); i != c[u].end(); i++) {
                if (--indegree[*i] == 0) q[lab[*i]].push(*i);
            }
        }
        moves++;
        side = !side;
    }
    return moves - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int num; cin >> num;
    while (num--) {
      int n, e, m = 0; cin >> n >> e;
      vector<int> lab(n), indegree(n, 0);
      vv c(n);
      for (long i = 0; i < n; i++) {
          cin >> lab[i];
          lab[i]--;
      }
      for (long i = 0; i < e; i++) {
          int s,d; cin >> s >> d;
          s--; d--;
          c[s].push_back(d);
          indegree[d]++;
      }
      long v1 = topological_sort(indegree, c, lab, 0, n);
      long v2 = topological_sort(indegree, c, lab, 1, n);
      cout << min(v1,v2) << '\n';
    }
}