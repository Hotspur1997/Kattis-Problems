#include <bits/stdc++.h>
#define START 0
using namespace std;
typedef pair<bool, int> iPair;
typedef vector<vector<int>> vv;

int bfs (vv &connection,int* move, int n) {
    int count = 0;
    bool* visited = new bool[n];
    for (long i = 0; i < n; i++) visited[i] = false;
    queue<iPair> curr;
    visited[START] = true;
    curr.push(make_pair(false, START));
    bool noForce = true;
    while (!curr.empty()) {
        int from = curr.front().second;
        bool bug = curr.front().first;
        curr.pop();
        if (move[from] != -1) {
            noForce = false;
            if (!visited[move[from]]) {
              visited[move[from]] = true;
              curr.push(make_pair(bug, move[from]));
            }
            
        } else noForce = true;
        
        if (noForce) count++;
        if (!bug) {
            for (auto i = connection[from].begin(); i != connection[from].end(); i++) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    curr.push(make_pair(true, *i));
                }
            }
        }
    }
    delete[] visited;
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int e;
    cin >> e;
    int* move = new int[n];
    vv connection (n);
    for (long i = 0; i < n; i++) move[i] = -1;
    for (long i = 0; i < e; i++) {
        int src, dst;
        cin >> src;
        cin >> dst;
        if (src < 0) {
            src = -src;
            move[src- 1] = dst - 1;
            
        } else connection[src - 1].push_back(dst - 1);
    }
    cout << bfs (connection, move, n) << endl;
    delete[] move;
    return 0;
}