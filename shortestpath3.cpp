#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<long, long>, long> iPair;
#define INF 20000000

void beliman_ford(iPair* edges, long* dist, long n, long e, long s) {
    dist[s] = 0;
    for (long i = 0; i < n - 1; i++) {
        for (long j = 0; j < e; j++) {
            long u = edges[j].first.first;
            long v = edges[j].first.second;
            long w = edges[j].second;
            if (dist[u] != INF && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }
    
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < e; j++) {
            long u = edges[j].first.first;
            long v = edges[j].first.second;
            long w = edges[j].second;
            if (dist[u] != INF && dist[u] + w < dist[v]) dist[v] = -INF;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        long n,e,q,s;
        cin >> n;
        cin >> e;
        cin >> q;
        cin >> s;
        if (!n && !e && !q && !s) break;
        iPair* edges = new iPair[e];
        long * dist = new long [n];
        long* queries = new long [q];
        for (long i = 0; i < n; i++) dist[i] = INF;
        for (long i = 0; i < e; i++) {
            long src,dst,weight;
            cin >> src;
            cin >> dst;
            cin >> weight;
            edges[i] = make_pair(make_pair(src, dst), weight);
        }
        
        for (long i = 0; i < q; i++) cin >> queries[i];
        beliman_ford(edges, dist, n, e, s);
        
        for (long i = 0; i < q; i++) {
            if (dist[queries[i]] == -INF) {
                cout << "-Infinity" << '\n';
                continue;
            } 
            if (dist[queries[i]] == INF) {
                cout << "Impossible" << '\n';
                continue;
            } 
            cout << dist[queries[i]] << '\n';
        }
        delete[] queries; delete[] edges; delete[] dist;
        cout << '\n';
    }
}