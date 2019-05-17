#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

int relabel(int i, int j, int c) {
    return c * i + j;
}

int find (int* pred, int a) {
    if (pred[a] < 0) return a;
    return pred[a] = find(pred, pred[a]);
}

int bounds (int i, int j, int r, int c) {
    return i >= 0 && i < r && j >= 0 && j < c;
}
void bfs (char** a, int* pred, int r, int c, int rmax, int cmax) {
    vector<iPair> move = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    bool isOne = (a[r][c] == '1') ? true : false;
    int src = relabel(r,c,cmax);
    for (iPair i : move) {
        int rIndex = r + i.first;
        int cIndex = c + i.second;
        if (bounds(rIndex,cIndex, rmax,cmax)) {
            int r1 = relabel(rIndex, cIndex, cmax);
            if (isOne) {
                if (a[rIndex][cIndex] == '1') {
                    int a1 = find(pred, src);
                    int b1 = find(pred, r1);
                    if (a1 != b1) pred[b1] = a1;
                }
            } else if (a[rIndex][cIndex] == '0') {
               int a1 = find(pred, src);
               int b1 = find(pred, r1);
               if (a1 != b1) pred[b1] = a1;
            }
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int r,c,q; cin >> r >> c;
    char** a = new char*[r];
    int* pred = new int[r *c];
    for (long i = 0; i < r * c; i++) pred[i] = -1;
    for (long i = 0; i < r; i++) {
        a[i] = new char[c];
        for (long j = 0; j < c; j++) cin >> a[i][j];
    }
    
    for (long i = 0; i < r; i++) {
        for (long j = 0; j < c; j++) bfs (a, pred, i, j, r, c);
    }
    
    cin >> q;
    for (long i = 0; i < q; i++) {
        int s1,s2,d1,d2; cin >> s1 >> s2 >> d1 >> d2;
        s1--; s2--; d1--; d2--;
        if (a[s1][s2] != a[d1][d2]) {
            cout << "neither" << endl;
        } else if (s1 == d1 && s2 == d2) {
            if (a[s1][s2] == '1') cout << "decimal" << endl;
            if (a[s1][s2] == '0') cout << "binary" << endl;
        } else {
            int i1 = relabel(s1,s2,c);
            int i2 = relabel(d1,d2,c);
            int r1 = find(pred, i1);
            int r2 = find(pred, i2);
            if (r1 == r2) {
                if (a[s1][s2] == '1') cout << "decimal" << endl;
                if (a[s1][s2] == '0') cout << "binary" << endl;
            } else cout << "neither" << endl;
        }
    }
    for (long i = 0; i < r; i++) {
        delete a[i]; a[i] = 0;
    }
    delete a; a = 0; delete pred; pred = 0;
}