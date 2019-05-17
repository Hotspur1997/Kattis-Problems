#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

bool inbound(long i, long j, long r, long c) {
    return i >= 0 && j >= 0 && i < r && j < c;
}

void spread (vector<vector<char>> &a, queue<iPair> &v, queue<iPair> &newV, long rmax, long cmax) {
    vector<iPair> move = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while (!v.empty()) {
        int r = v.front().first;
        int c = v.front().second;
        v.pop();
        for (iPair i : move) {
            int newr = r + i.first;
            int newc = c + i.second;
            if (inbound(newr,newc, rmax, cmax) && (a[newr][newc] == '.' || a[newr][newc] == 'J')) {
                a[newr][newc] = 'F';
                newV.push(make_pair(newr,newc));
            }
        }
    }
}

void bfs (vector<vector<char>> &a, queue<iPair> &p, queue<iPair> &newP, bool &found, long rmax, long cmax) {
    vector<iPair> move = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while (!p.empty()) {
        iPair temp = p.front();
        p.pop();
        int r = temp.first;
        int c = temp.second;
        for (iPair i : move) {
            int newr = r + i.first;
            int newc = c + i.second;
            if (inbound(newr,newc, rmax, cmax) && a[newr][newc] == '.') {
                a[newr][newc] = 'J';
                if (newr == 0 || newr == rmax - 1 || newc == 0 || newc == cmax - 1) found = true;
                newP.push(make_pair(newr,newc));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int res = 0, rmax, cmax; cin >> rmax >> cmax;
    vector<vector<char>> a(rmax);
    queue<iPair> v, p;
    bool found = false;
    iPair s;
    for (int i = 0; i < rmax; i++) {
        for (int j = 0; j < cmax; j++) {
            char ca; cin >> ca;
            a[i].push_back(ca);
        }
    }
    for (int i = 0; i < rmax; i++) {
        for (int j = 0; j < cmax; j++) {
            if (a[i][j] == 'F') v.push(make_pair(i,j));
            if (a[i][j] == 'J') s = make_pair(i,j);
        }
    }
    if (s.first == rmax - 1 || s.second == cmax - 1 ||
        !s.first || !s.second) {
        cout << 1 << endl;
        return 0;
    }
        
    p.push(s);
    while ((!p.empty() || !v.empty()) && !found) {
        queue<iPair> newP, newV;
        spread(a, v, newV, rmax, cmax);
        bfs(a, p, newP, found, rmax, cmax);
        v = newV;
        p = newP;
        res++;
    }
    if (found) {
        cout << res + 1 << '\n';
    } else cout << "IMPOSSIBLE" << '\n';
}