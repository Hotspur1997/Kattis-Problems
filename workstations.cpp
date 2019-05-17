#include <bits/stdc++.h>
using namespace std;
typedef pair<long, long> iPair;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n, m, res = 0; cin >> n >> m;
    vector<iPair> p;
    for (long i = 0; i < n; i++) {
        long r1,r2; cin >> r1 >> r2;
        p.push_back(make_pair(r1,r2));
    }
    sort(p.begin(), p.end());
    priority_queue<long, vector<long>, greater<long>> pq;
    for (long i = 0; i < p.size(); i++) {
       while (!pq.empty() && p[i].first > pq.top() + m) pq.pop();
        if (!pq.empty() && p[i].first >= pq.top()) {
           pq.pop();
           res++;
        }
        pq.push(p[i].first + p[i].second);
    }
    cout << res;
}