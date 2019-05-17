#include <bits/stdc++.h>
using namespace std;
typedef pair<long, long> iPair;

void find(long** a, bool** v, bool** vi, long k1, long c) {
    
    bool found = false;
    for (long i = 0; i < c; i++) {
        for (long j = 0; j < c; j++) {
            if (a[i][j] == k1) {
                found = true;
                v[i][j] = true;
                vi[i][j] = true;
                break;
            }
        }
        if (found) break;
    }
}

void bfs (long** a, bool** v, bool** vi, long rIndex, long cIndex, long c, long &result) {
    
    queue<iPair> curr;
    vi[rIndex][cIndex] = true;
    curr.push(make_pair(rIndex, cIndex));
    while(!curr.empty()) {
        
        rIndex = curr.front().first;
        cIndex = curr.front().second;
        curr.pop();
        if (cIndex + 1 < c && v[rIndex][cIndex + 1]) result++;
        if (cIndex - 1 >= 0 && v[rIndex][cIndex - 1]) result++;
        if (rIndex + 1 < c && v[rIndex + 1][cIndex]) result++;
        if (rIndex - 1 >= 0 && v[rIndex - 1][cIndex]) result++;
        if (rIndex + 1 < c && cIndex + 1 < c && v[rIndex + 1][cIndex + 1]) result++;
        if (rIndex - 1 >= 0 && cIndex - 1 >= 0 && v[rIndex - 1][cIndex - 1]) result++;
        
        if (cIndex + 1 < c && !v[rIndex][cIndex + 1] && !vi[rIndex][cIndex + 1]) {
            vi[rIndex][cIndex + 1] = true;
            curr.push(make_pair(rIndex,cIndex + 1));
        }
        if (cIndex - 1 >= 0 && !v[rIndex][cIndex - 1] && !vi[rIndex][cIndex - 1]) {
            vi[rIndex][cIndex - 1] = true;
            curr.push(make_pair(rIndex, cIndex - 1));
        }
        if (rIndex + 1 < c && !v[rIndex + 1][cIndex] && !vi[rIndex + 1][cIndex]) {
            vi[rIndex + 1][cIndex] = true;
            curr.push(make_pair(rIndex + 1, cIndex));
        }
        if (rIndex - 1 >= 0 && !v[rIndex - 1][cIndex] && !vi[rIndex - 1][cIndex]) {
            vi[rIndex - 1][cIndex] = true;
            curr.push(make_pair(rIndex - 1, cIndex));
        }
        if (rIndex + 1 < c && cIndex + 1 < c && !v[rIndex + 1][cIndex + 1] && !vi[rIndex + 1][cIndex + 1]) {
            vi[rIndex + 1][cIndex + 1] = true;
            curr.push(make_pair(rIndex + 1, cIndex + 1));
        }
        if (rIndex - 1 >= 0 && cIndex - 1 >= 0 && !v[rIndex - 1][cIndex - 1] && !vi[rIndex - 1][cIndex - 1]) {
            vi[rIndex - 1][cIndex - 1] = true;
            curr.push(make_pair(rIndex - 1, cIndex - 1));
        }
    }
}

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long n, k; cin >> n >> k;
    long c = 2 * n + 1, result = 0;
    long rCount = 1, cCount = n, offset = 1;
    long** a = new long* [c];
    bool** v = new bool*[c];
    bool** vi = new bool*[c];
    for (long i = 0; i < c; i++) {
        a[i] = new long[c];
        v[i] =  new bool[c];
        vi[i] = new bool[c];
        for (long j = 0; j < c; j++) {
            v[i][j] = false;
            vi[i][j] = false;
        }
    }
   
    for (long i = 0; i < c; i++) a[0][i] = -1;
    for (long i = 1; i < n + 1; i++) {
        for (long j = 0; j < c; j++) {
            
            if (!j ||  j == c - 1) {
                a[i][j] = -1;
            } else {
                
                if (j < cCount + 1) {
                    a[i][j] = rCount;
                    rCount++;
                } else {
                    a[i][j] = -1;
                }
            }
        }
        cCount++;
    }
    
    cCount--;
    for (long i = n + 1; i < 2 * n; i++) {
        long cOffset = 0, jOffset = 0;
        
        for (long j = 0; j < c; j ++) {
            if (!j || j == c - 1) {
                a[i][j] = -1;
            } else {
                
                if (cOffset < offset) {
                    a[i][j] = -1;
                    cOffset++;
                } else {
                    if (jOffset < cCount) {
                        a[i][j] = rCount;
                        rCount++;
                        jOffset++;
                    } else {
                        a[i][j] = -1;
                    }
                }
                
            }
        }
        offset++;
        cCount--;
    }
    for (long i = 0; i < c; i++) a[c - 1][i] = -1;
    
    for (long i = 0; i < k; i++) {
        long k1; cin >> k1;
         find(a, v, vi, k1, c);
    }
    bfs(a, v, vi, 0, 0, c, result);
   
    for (long i = 0; i < c; i++) {
        delete a[i]; a[i] = 0;
        delete v[i]; v[i] = 0;
        delete vi[i]; vi[i] = 0;
    }
    
    delete[] a; a = 0;
    delete[] v; v = 0;
    delete[] vi; vi = 0;
    cout << result << '\n';
}