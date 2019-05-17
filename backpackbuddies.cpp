#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef pair<long,long> iPair;
typedef vector<iPair> v;

void dijkstra(v* distance, long* dist, long n) {
    
    dist[0] = 0;
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push(make_pair(0,0));
    while (!pq.empty()) {
        
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        for (auto i = distance[u].begin(); dist[u] >= weight && i != distance[u].end(); i++) {
            long v = i -> first;
            long weight = i -> second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

void modified_dijkstra(v* distance, long* dist, long n) {
    
    dist[0] = 0;
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    pq.push(make_pair(0,0));
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();
        for (auto i = distance[u].begin(); dist[u] >= weight && i != distance[u].end(); i++) {
            long v = i -> first;
            long weight = i -> second;
            long dummy = dist[u] % 12;
            if (dummy + weight <= 12) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            } else if (dist[u] + 12 - dummy + weight < dist[v]) {
                dist[v] = dist[u] + 12 - dummy + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n,e; cin >> n >> e;
    v* distance = new v[n];
    long* dist1 = new long [n];
    long* dist2 = new long[n];
    
    for (long i = 0; i < n; i++) {
        
        dist2[i] = LONG_MAX;
        dist1[i] = LONG_MAX;
    }
    
    for (long i = 0; i < e; i++) {
        
        long src,dst,weight;
        cin >> src;
        cin >> dst;
        cin >> weight;
        distance[src].push_back(make_pair(dst, weight));
        distance[dst].push_back(make_pair(src, weight));
    }
    
    dijkstra(distance, dist1, n);
    long kCost = 0;
    if (dist1[n - 1] % 12 == 0) {
        kCost = dist1[n - 1] + ((dist1[n - 1] / 12) - 1) * 12;
    } else kCost = dist1[n - 1] + (dist1[n - 1] / 12) * 12;
    
    modified_dijkstra(distance, dist2, n);
    long dCost = dist2[n - 1];
    if (dCost % 12 == 0) {
        dCost = dist2[n - 1] + ((dist2[n - 1] / 12) - 1) * 12;
    } else dCost = dist2[n - 1] + (dist2[n - 1] / 12) * 12;
    
    cout << dCost - kCost << '\n';
    delete[] distance; distance = 0;
    delete[] dist1; dist1 = 0;
    delete[] dist2; dist2 = 0;
}