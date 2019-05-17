#include <bits/stdc++.h>
using namespace std;
typedef pair<long, long> iPair;
typedef pair<pair<long, long>, pair<long, long>> iiPair;
typedef vector<iiPair> vv;

long wait(long currDist, long original, long increment) {
    
    if (currDist <= original) return original;
    if (increment && (currDist - original) % increment == 0) return currDist;
    if (increment) {
      long quotient = (currDist - original) / increment;
      quotient++;
      long result = original + quotient * increment;
      return result;
    }
    return LONG_MAX;
}

void modified_dijkstra(vv* connection, map<iPair, vector<long>> &m, long* dist, long src) {
    
    dist[src] = 0;
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push(make_pair(dist[src], src));
    
    while (!pq.empty()) {
        
        long u = pq.top().second;
        pq.pop();
        for (auto i = connection[u].begin(); i != connection[u].end(); i++) {
        
            long v = (i -> first).first;
            long weight = (i -> first).second;
            long original = (i -> second).first;
            long increment = (i -> second).second;
            long duration = wait(dist[u], original, increment);
            if (duration != LONG_MAX && duration + weight < dist[v]) {
                dist[v] = duration + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
      long n, e, q, s;
      cin >> n;
      cin >> e;
      cin >> q;
      cin >> s;
      if (!n && !e && !q && !s) break;
      map<iPair, vector<long>> m;
      vv* connection = new vv[n];
      long* queries = new long[q];
      long* dist = new long[n];
      for (long i = 0; i < n; i++) dist[i] = LONG_MAX;
      for (long i = 0; i < e; i++) {
          long src,dst, weight, original, increment;
          cin >> src;
          cin >> dst;
          cin >> original;
          cin >> increment;
          cin >> weight;
          connection[src].push_back(make_pair(make_pair(dst, weight), make_pair(original, increment)));
      }
      for (long i = 0; i < q; i++) cin >> queries[i];
      modified_dijkstra(connection, m, dist, s);
        
      for (long i = 0; i < q; i++) {
        if (dist[queries[i]] == LONG_MAX) {
            cout << "Impossible" << '\n';
            } else cout << dist[queries[i]] << '\n';
        }
        cout << '\n';
        delete[] queries;
        delete[] dist;
        delete[] connection;
    }
}