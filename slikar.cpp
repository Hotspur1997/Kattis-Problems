#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> iPair;

bool inbounds(int i, int j, int r, int c) {
    return i < r && i >= 0 && j < c && j >= 0;
}

void bfs (char** a, queue<iPair> &newq, queue<iPair> &oldq, bool fire, bool &f, int rmax, int cmax) {
    
    vector<iPair> move = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while (!oldq.empty()) {
        iPair t = oldq.front();
        oldq.pop();
        for (iPair i : move) {
            int r = t.first + i.first;
            int c = t.second + i.second;
            if (inbounds(r, c, rmax, cmax)) {
                if (fire) {
                    if (a[r][c] == '.' || a[r][c] == 'S') {
                        a[r][c] = '*';
                        newq.push(make_pair(r,c));
                    }
                } else {
                    if (a[r][c] == 'D') {
                        f = true;
                        break;
                    }
                    if (a[r][c] == '.') {
                        a[r][c] = 'S';
                        newq.push(make_pair(r,c));
                    }
                }
            }
        }
        if (f) break;
    }
}
int main() {
    
    int r,c, res = 0; cin >> r >> c;
    char** a = new char*[r];
    for (int i = 0; i < r; i++) {
        a[i] = new char[c];
        for (long j = 0; j < c; j++) cin >> a[i][j];
    }
    iPair s;
    bool found = false;
    queue<iPair> f,p;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == '*') f.push(make_pair(i,j));
            if (a[i][j] == 'S') p.push(make_pair(i,j));
        }
    }
    
    while ((!f.empty() || !p.empty()) && !found) {
        queue<iPair> newF, newP;
        bfs(a, newF, f, true, found, r, c);
        bfs(a, newP, p, false, found, r, c);
        p = newP;
        f = newF;
        res++;
    }
    if (found) {
        cout << res << '\n';
    } else cout << "KAKTUS" << '\n';
    for (int i = 0; i < r; i++) {
        delete a[i]; a[i] = 0;
    }
    delete a; a = 0;
}